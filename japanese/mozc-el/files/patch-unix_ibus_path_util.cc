--- unix/ibus/path_util.cc.org	2010-11-06 10:57:33.500187940 +0900
+++ unix/ibus/path_util.cc	2010-11-06 10:58:12.395186886 +0900
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
