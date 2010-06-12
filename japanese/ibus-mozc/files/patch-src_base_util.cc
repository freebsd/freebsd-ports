--- base/util.cc.org	2010-06-11 18:01:03.000000000 +0900
+++ base/util.cc	2010-06-12 10:04:16.922969013 +0900
@@ -1489,7 +1489,7 @@
 #endif  // OS_MACOSX
 
 #ifdef OS_LINUX
-  return "/usr/lib/mozc";
+  return "@@LOCALBASE@@/share/ibus-mozc/server";
 #endif  // OS_LINUX
 }
 
