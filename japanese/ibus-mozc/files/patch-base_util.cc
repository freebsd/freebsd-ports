--- base/util.cc.org	2010-09-18 12:31:34.023397161 +0900
+++ base/util.cc	2010-09-18 12:34:43.496234072 +0900
@@ -1525,9 +1525,13 @@
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
