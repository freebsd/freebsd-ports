--- converter/other/pnmtopng.c.orig	Thu Apr 25 09:37:11 2002
+++ converter/other/pnmtopng.c	Tue Jun 18 00:00:00 2002
@@ -1857,8 +1857,13 @@
       fprintf(stderr,"pnmtopng version %s.\n", VERSION);
       fprintf(stderr, "   Compiled with libpng %s; using libpng %s.\n",
         PNG_LIBPNG_VER_STRING, png_libpng_ver);
+#ifdef zlib_version
       fprintf(stderr, "   Compiled with zlib %s; using zlib %s.\n",
         ZLIB_VERSION, zlib_version);
+#else
+      fprintf(stderr, "   Compiled with zlib %s.\n",
+        ZLIB_VERSION);
+#endif
       fprintf(stderr,    
         "   Compiled with %d-bit netpbm support (PPM_OVERALLMAXVAL = %d).\n",
         pm_maxvaltobits (PPM_OVERALLMAXVAL), PPM_OVERALLMAXVAL);
