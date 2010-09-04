--- base/util.cc.org	2010-09-03 11:24:20.268706017 +0900
+++ base/util.cc	2010-09-03 11:24:57.363718651 +0900
@@ -1497,7 +1497,7 @@
 #endif  // OS_MACOSX
 
 #ifdef OS_LINUX
-  return "/usr/lib/mozc";
+  return "@@LOCALBASE@@/bin";
 #endif  // OS_LINUX
 }
 
