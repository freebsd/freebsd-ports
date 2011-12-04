--- base/util.cc.orig	2011-12-04 16:22:26.112610903 +0900
+++ base/util.cc	2011-12-04 16:46:50.958606064 +0900
@@ -2592,9 +2592,13 @@
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
