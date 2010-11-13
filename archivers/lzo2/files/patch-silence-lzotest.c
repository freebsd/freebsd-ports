--- lzotest/lzotest.c.orig	2010-10-31 18:21:28.000000000 +0100
+++ lzotest/lzotest.c	2010-11-13 00:37:17.279807378 +0100
@@ -233,7 +233,7 @@
 // command line options
 **************************************************************************/
 
-int opt_verbose = 2;
+int opt_verbose = 1;
 
 long opt_c_loops = 0;
 long opt_d_loops = 0;
@@ -1928,6 +1928,7 @@
         if ((*s == '/' || *s == '\\') && s[1])
             progname = s + 1;
 
+#if 0
 #if defined(__LZO_PROFESSIONAL__)
     printf("\nLZO Professional real-time data compression library (v%s, %s).\n",
            lzo_version_string(), lzo_version_date());
@@ -1937,6 +1938,7 @@
            lzo_version_string(), lzo_version_date());
     printf("Copyright (C) 1996-2010 Markus Franz Xaver Johannes Oberhumer\nAll Rights Reserved.\n\n");
 #endif
+#endif
 
 
 /*
