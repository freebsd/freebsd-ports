Generalize the "rewind on pipes" hack to work with all Torek-based stdio's
without having to check for each one.  Fix will appear in the next release.

http://sourceforge.net/tracker/index.php?func=detail&aid=2847998&group_id=10706&atid=310706

--- src/formats.c	2009-06-14 20:14:53.000000000 -0500
+++ src/formats.c	2009-08-31 13:16:21.440822225 -0500
@@ -392,7 +392,7 @@
  * Works by resetting the FILE buffer pointer */
 static void UNUSED rewind_pipe(FILE * fp)
 {
-#if defined _NEWLIB_VERSION || defined __APPLE__
+#if defined _FSTDIO /* Torek stdio (i.e. most BSD-derived libc's) */
   fp->_p -= AUTO_DETECT_SIZE;
   fp->_r += AUTO_DETECT_SIZE;
 #elif defined __GLIBC__
