--- src/corelib/configure.cmake.orig	2026-01-13 10:18:17 UTC
+++ src/corelib/configure.cmake
@@ -560,6 +560,10 @@ qt_config_compile_test(renameat2
 #include <fcntl.h>
 #include <stdio.h>
 
+#if defined(__FreeBSD__) && !defined(RENAME_WHITEOUT)
+#define RENAME_WHITEOUT 0
+#endif
+
 int main(int, char **argv)
 {
     /* BEGIN TEST: */
@@ -889,7 +893,7 @@ qt_feature("renameat2" PRIVATE
 )
 qt_feature("renameat2" PRIVATE
     LABEL "renameat2()"
-    CONDITION ( LINUX OR HURD ) AND TEST_renameat2
+    CONDITION ( LINUX OR HURD OR FREEBSD ) AND TEST_renameat2
 )
 qt_feature("slog2" PRIVATE
     LABEL "slog2"
