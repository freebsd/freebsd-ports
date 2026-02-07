--- lzotest/lzotest.c.orig	2017-03-01 19:54:14 UTC
+++ lzotest/lzotest.c
@@ -206,7 +206,7 @@ enum {
 // command line options
 **************************************************************************/
 
-int opt_verbose = 2;
+int opt_verbose = 1;
 
 long opt_c_loops = 0;
 long opt_d_loops = 0;
@@ -1902,9 +1902,11 @@ int __lzo_cdecl_main main(int argc, char
         if ((*s == '/' || *s == '\\') && s[1])
             progname = s + 1;
 
+#if 0
     printf("\nLZO real-time data compression library (v%s, %s).\n",
            lzo_version_string(), lzo_version_date());
     printf("Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer\nAll Rights Reserved.\n\n");
+#endif
 
 
 /*
