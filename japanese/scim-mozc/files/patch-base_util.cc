--- base/util.cc.org	2010-10-16 11:56:45.879185798 +0900
+++ base/util.cc	2010-10-16 11:58:28.386189342 +0900
@@ -1571,9 +1571,13 @@
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
 
 string Util::GetServerPath() {
