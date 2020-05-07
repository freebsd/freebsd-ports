--- dwarves_fprintf.c.orig	2020-05-06 22:11:18 UTC
+++ dwarves_fprintf.c
@@ -7,6 +7,8 @@
   Copyright (C) 2007..2009 Arnaldo Carvalho de Melo <acme@redhat.com>
 */
 
+#include <sys/param.h>
+
 #include <dwarf.h>
 #include <errno.h>
 #include <stdio.h>
@@ -1910,12 +1912,7 @@ void cus__print_error_msg(const char *progname, const 
 void dwarves__fprintf_init(uint16_t user_cacheline_size)
 {
 	if (user_cacheline_size == 0) {
-		long sys_cacheline_size = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
-
-		if (sys_cacheline_size > 0)
-			cacheline_size = sys_cacheline_size;
-		else
-			cacheline_size = 64; /* Fall back to a sane value */
+		cacheline_size = CACHE_LINE_SIZE;
 	} else
 		cacheline_size = user_cacheline_size;
 }
