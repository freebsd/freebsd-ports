--- src/base/util.cc.org	2010-05-29 12:46:19.265746218 +0900
+++ src/base/util.cc	2010-05-29 20:52:31.971118268 +0900
@@ -1489,7 +1489,7 @@
 #endif  // OS_MACOSX
 
 #ifdef OS_LINUX
-  return "/usr/lib/mozc";
+  return "@@LOCALBASE@@/share/ibus-mozc/server";
 #endif  // OS_LINUX
 }
 
