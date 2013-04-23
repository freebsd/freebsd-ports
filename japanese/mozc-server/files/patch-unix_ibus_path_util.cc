--- unix/ibus/path_util.cc.orig	2013-04-21 03:48:44.435272531 +0900
+++ unix/ibus/path_util.cc	2013-04-21 04:12:51.235269303 +0900
@@ -30,14 +30,22 @@
 #include "unix/ibus/path_util.h"
 
 namespace {
+#ifdef __FreeBSD__
+const char kInstalledDirectory[] = "@@LOCALBASE@@/share/ibus-mozc";
+#else
 const char kInstalledDirectory[] = "/usr/share/ibus-mozc";
+#endif
 }
 
 namespace mozc {
 namespace ibus {
 
 string GetIconPath(const string &icon_file) {
+#ifdef __FreeBSD__
+  return string("@@LOCALBASE@@/share/ibus-mozc/icons/") + icon_file;
+#else
   return kInstalledDirectory + string("/") + icon_file;
+#endif
 }
 
 }  // namespace ibus
