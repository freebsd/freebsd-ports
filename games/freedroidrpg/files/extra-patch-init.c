--- src/init.c.orig	Mon Jul 18 02:00:54 2005
+++ src/init.c		Mon Jul 18 02:05:10 2005
@@ -58,14 +58,9 @@
  * section about 'Arithmethic', subsection on floating point control
  * functions.
  * ---------------------------------------------------------------------- */
-#if defined __APPLE_CC__
-/* turn off these function-call on OS X, where there are not present */
+/* turn off these function-call */
 int feenableexcept (int excepts) { return 0;}
 int fedisableexcept (int TheExceptionFlags ) { return 0; }
-#else
-extern int feenableexcept (int excepts);
-extern int fedisableexcept (int TheExceptionFlags );
-#endif
 
 /* ----------------------------------------------------------------------
  *
