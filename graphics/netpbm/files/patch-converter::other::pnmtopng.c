--- converter/other/pnmtopng.c.orig	Sun Jun 23 12:51:37 2002
+++ converter/other/pnmtopng.c	Sat Jul  6 00:00:00 2002
@@ -1903,8 +1903,13 @@
     */
     fprintf(stderr, "   Compiled with libpng %s.\n",
             PNG_LIBPNG_VER_STRING);
+#ifdef zlib_version
     fprintf(stderr, "   Compiled with zlib %s; using zlib %s.\n",
             ZLIB_VERSION, zlib_version);
+#else
+    fprintf(stderr, "   Compiled with zlib %s.\n",
+            ZLIB_VERSION);
+#endif
     fprintf(stderr,    
             "   Compiled with %d-bit netpbm support "
             "(PPM_OVERALLMAXVAL = %d).\n",
