--- ext/nanogui/src/common.cpp.orig	2016-10-15 20:12:12 UTC
+++ ext/nanogui/src/common.cpp
@@ -24,7 +24,7 @@
 #if !defined(_WIN32)
     #include <locale.h>
     #include <signal.h>
-    #include <sys/dir.h>
+    #include <dirent.h>
 #endif
 
 NAMESPACE_BEGIN(nanogui)
@@ -248,7 +248,7 @@ std::string file_dialog(const std::vector<std::pair<st
     return std::string(ofn.lpstrFile);
 #else
     char buffer[FILE_DIALOG_MAX_BUFFER];
-    std::string cmd = "/usr/bin/zenity --file-selection ";
+    std::string cmd = "zenity --file-selection ";
     if (save)
         cmd += "--save ";
     cmd += "--file-filter=\"";
