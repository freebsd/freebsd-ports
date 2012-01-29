--- base/util.cc.orig	2012-01-29 13:42:31.192806902 +0900
+++ base/util.cc	2012-01-29 13:49:21.226806684 +0900
@@ -2636,9 +2636,13 @@
   return MacUtil::GetServerDirectory();
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   return "/usr/lib/mozc";
 #endif  // OS_LINUX
+
+#ifdef __FreeBSD__
+  return "@@LOCALBASE@@/bin";
+#endif
 }
 
 string Util::GetDocumentDirectory() {
