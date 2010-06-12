--- unix/ibus/path_util.cc.org	2010-06-11 18:00:39.000000000 +0900
+++ unix/ibus/path_util.cc	2010-06-12 10:23:37.582580151 +0900
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
