--- unix/ibus/path_util.cc.org	2010-06-17 15:59:08.044438083 +0900
+++ unix/ibus/path_util.cc	2010-06-26 16:38:18.218403536 +0900
@@ -30,14 +30,14 @@
 #include "unix/ibus/path_util.h"
 
 namespace {
-const char kInstalledDirectory[] = "/usr/share/ibus-mozc";
+const char kInstalledDirectory[] = "@@LOCALBASE@@/share/ibus-mozc";
 }
 
 namespace mozc {
 namespace ibus {
 
 string GetIconPath(const string &icon_file) {
-  return kInstalledDirectory + string("/") + icon_file;
+  return string("@@LOCALBASE@@/share/mozc-additions/icons/") + icon_file;
 }
 
 }  // namespace ibus
