This test reduces the lzotest verbosity so that it doesn't print anything
on success.

--- lzotest/lzotest.c.orig	2008-06-01 10:01:36.000000000 +0200
+++ lzotest/lzotest.c	2008-06-01 10:03:10.000000000 +0200
@@ -226,7 +226,7 @@
 
 struct corpus_entry_t;
 
-int opt_verbose = 2;
+int opt_verbose = 1;
 
 long opt_c_loops = 0;
 long opt_d_loops = 0;
@@ -1910,10 +1910,12 @@
 #elif defined(LZOTEST_USE_DYNLOAD)
 #  include "dynload/init.ch"
 #else
+#if 0
     printf("\nLZO real-time data compression library (v%s, %s).\n",
            lzo_version_string(), lzo_version_date());
     printf("Copyright (C) 1996-2008 Markus Franz Xaver Johannes Oberhumer\nAll Rights Reserved.\n\n");
+#endif
 #endif
 
 
 /*
