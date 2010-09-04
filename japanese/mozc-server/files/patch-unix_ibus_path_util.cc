--- unix/ibus/path_util.cc.org	2010-09-03 11:46:40.275135605 +0900
+++ unix/ibus/path_util.cc	2010-09-03 11:47:34.058766206 +0900
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
+  return string("@@LOCALBASE@@/share/ibus-mozc/icons/") + icon_file;
 }
 
 }  // namespace ibus
