--- OpenCircuitX/src/core/update_check.cpp.orig	2026-07-20 23:33:17 UTC
+++ OpenCircuitX/src/core/update_check.cpp
@@ -2,15 +2,18 @@
 #include "core/version.h"
 #include <wx/tokenzr.h>
 #include <thread>
+#ifdef WIN32
 #include <windows.h>
 #include <wininet.h>
 #pragma comment(lib, "wininet.lib")
+#endif
 
 const char* const OCX_LATEST_DOWNLOAD_URL =
     "https://github.com/openlab-x/OpenCircuitX/releases/latest/download/OpenCircuitX-Setup.exe";
 
 wxString OCXFetchRemoteVersion()
 {
+#ifdef WIN32
     HINTERNET hNet = InternetOpenA("OpenCircuitX/" OCX_VERSION_STRING,
                                    INTERNET_OPEN_TYPE_PRECONFIG,
                                    nullptr, nullptr, 0);
@@ -36,6 +39,9 @@ wxString OCXFetchRemoteVersion()
     InternetCloseHandle(hNet);
 
     result.Trim(true).Trim(false);
+    return result;
+#endif
+    wxString result;
     return result;
 }
 
