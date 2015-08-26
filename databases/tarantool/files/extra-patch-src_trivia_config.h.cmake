--- src/trivia/config.h.cmake.orig	2015-05-15 14:01:37 UTC
+++ src/trivia/config.h.cmake
@@ -21,6 +21,13 @@
 #cmakedefine TARGET_OS_LINUX 1
 /*  Defined if building for FreeBSD */
 #cmakedefine TARGET_OS_FREEBSD 1
+#if defined(TARGET_OS_FREEBSD)
+/*
+ * Fix build with GCC 4.8 when _ThreadRuneLocale undeclared
+ * on FreeBSD.
+ */
+#define __RUNETYPE_INTERNAL
+#endif
 /*  Defined if building for Darwin */
 #cmakedefine TARGET_OS_DARWIN 1
 /*
