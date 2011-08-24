--- ./lzotest/lzotest.c.orig	2011-04-23 12:55:35.000000000 +0200
+++ ./lzotest/lzotest.c	2011-05-10 21:47:16.000000000 +0200
@@ -234,7 +234,7 @@
 // command line options
 **************************************************************************/
 
-int opt_verbose = 2;
+int opt_verbose = 1;
 
 long opt_c_loops = 0;
 long opt_d_loops = 0;
@@ -1929,6 +1931,7 @@
         if ((*s == '/' || *s == '\\') && s[1])
             progname = s + 1;
 
+#if 0
 #if defined(__LZO_PROFESSIONAL__)
     printf("\nLZO Professional real-time data compression library (v%s, %s).\n",
            lzo_version_string(), lzo_version_date());
@@ -1938,6 +1941,7 @@
            lzo_version_string(), lzo_version_date());
     printf("Copyright (C) 1996-2011 Markus Franz Xaver Johannes Oberhumer\nAll Rights Reserved.\n\n");
 #endif
+#endif
 
 
 /*
