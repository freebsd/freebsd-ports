--- bootloader/src/main.c.orig	2024-01-16 22:55:44 UTC
+++ bootloader/src/main.c
@@ -36,7 +36,9 @@
 #include "pyi_win32_utils.h"
 
 #ifdef __FreeBSD__
+    #include <sys/cdefs.h>
     #include <floatingpoint.h>
+    #include <ieeefp.h>
 #endif
 
 #if defined(_WIN32)
@@ -88,21 +90,9 @@ main(int argc, char **argv)
 main(int argc, char **argv)
 {
     int res;
-
-    #ifdef __FreeBSD__
-    fp_except_t m;
-
-    /* 754 requires that FP exceptions run in "no stop" mode by default,
-     * and until C vendors implement C99's ways to control FP exceptions,
-     * Python requires non-stop mode.  Alas, some platforms enable FP
-     * exceptions by default.  Here we disable them.
-     */
-    m = fpgetmask();
-    fpsetmask(m & ~FP_X_OFL);
-    #endif
 
     res = pyi_main(argc, argv);
     return res;
 }
 
-#endif  /* defined(WIN32) */
+#endif  /* defined(WIN32) */
\ No newline at end of file
