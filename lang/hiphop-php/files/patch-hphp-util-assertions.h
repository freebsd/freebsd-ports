--- hphp/util/assertions.h.orig	2013-07-22 00:36:45.262881238 +0200
+++ hphp/util/assertions.h	2013-07-22 00:37:05.484417990 +0200
@@ -86,7 +86,7 @@
                         const char* file,
                         unsigned int line,
                         const char* func) {
-#if !defined(NDEBUG) && !defined(__APPLE__)
+#if !defined(NDEBUG) && !defined(__APPLE__) && !defined(__FreeBSD__)
   __assert_fail(e, file, line, func);
 #else
   extern void impl_assert_fail(const char*,
