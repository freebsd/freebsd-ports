--- ext/nanogui/src/common.cpp.orig	2016-10-15 20:12:12 UTC
+++ ext/nanogui/src/common.cpp
@@ -248,7 +248,7 @@ std::string file_dialog(const std::vecto
     return std::string(ofn.lpstrFile);
 #else
     char buffer[FILE_DIALOG_MAX_BUFFER];
-    std::string cmd = "/usr/bin/zenity --file-selection ";
+    std::string cmd = "zenity --file-selection ";
     if (save)
         cmd += "--save ";
     cmd += "--file-filter=\"";
