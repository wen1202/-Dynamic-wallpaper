#include<iostream>
#include<windows.h>
#include<tchar.h>
using namespace std;
BOOL CALLBACK EnumWindowsProc(_In_ HWND hwnd, _In_ LPARAM Lparam)
{
	HWND hDefView = FindWindowEx(hwnd, 0, L"SHELLDLL_DefView", 0);
	if (hDefView != 0) {
		HWND hWorkerw = FindWindowEx(0, hwnd, L"WorkerW", 0);
		ShowWindow(hWorkerw, SW_HIDE);
		return FALSE;
	}
	return TRUE;
}
int main() {
	HWND hProgman = FindWindow(L"Progman", 0);
	SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);
	HWND mpvplay = FindWindow(L"mpv", 0);
	HWND console = FindWindow(L"ConsoleWindowClass", 0);
	SetParent(mpvplay, hProgman);
	EnumWindows(EnumWindowsProc, 0);
	SetWindowPos(mpvplay, HWND_TOP, 0, 0, 1920, 1080, SWP_SHOWWINDOW);
	ShowWindow(console, SW_MINIMIZE);
	return 0;
}
