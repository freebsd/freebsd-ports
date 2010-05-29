--- src/unix/ibus/path_util.cc.org	2010-05-29 12:45:05.983913471 +0900
+++ src/unix/ibus/path_util.cc	2010-05-29 21:43:40.031728485 +0900
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
+  return kInstalledDirectory + string("/icons/") + icon_file;
 }
 
 }  // namespace ibus
