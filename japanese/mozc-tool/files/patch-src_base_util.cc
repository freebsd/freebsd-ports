--- base/util.cc.org	2010-06-17 15:59:08.035797879 +0900
+++ base/util.cc	2010-06-26 15:18:24.444371641 +0900
@@ -1493,7 +1493,7 @@
 #endif  // OS_MACOSX
 
 #ifdef OS_LINUX
-  return "/usr/lib/mozc";
+  return "@@LOCALBASE@@/bin";
 #endif  // OS_LINUX
 }
 
