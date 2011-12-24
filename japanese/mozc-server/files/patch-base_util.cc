--- base/util.cc.orig	2011-12-24 13:17:13.099092285 +0900
+++ base/util.cc	2011-12-24 13:35:51.531092368 +0900
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
