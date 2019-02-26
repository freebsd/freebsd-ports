--- src/AppFrame.cpp.orig	2019-02-25 02:52:05 UTC
+++ src/AppFrame.cpp
@@ -34,7 +34,7 @@
 #include <wx/numformatter.h>
 #include <stddef.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "CubicSDR.xpm"
 #endif
 
@@ -79,7 +79,7 @@ std::vector<std::string> str_explode(const std::string
 AppFrame::AppFrame() :
         wxFrame(NULL, wxID_ANY, CUBICSDR_TITLE), activeDemodulator(nullptr) {
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     SetIcon(wxICON(cubicsdr));
 #endif
 
