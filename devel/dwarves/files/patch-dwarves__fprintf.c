--- dwarves_fprintf.c.orig	2016-06-30 19:30:28 UTC
+++ dwarves_fprintf.c
@@ -9,6 +9,9 @@
   published by the Free Software Foundation.
 */
 
+/* For CACHE_LINE_SIZE */
+#include <sys/param.h>
+
 #include <dwarf.h>
 #include <errno.h>
 #include <stdio.h>
@@ -1699,7 +1702,14 @@ void cus__print_error_msg(const char *pr
 void dwarves__fprintf_init(uint16_t user_cacheline_size)
 {
 	if (user_cacheline_size == 0) {
+#if 0
 		long sys_cacheline_size = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
+#else
+		/*
+		 * CEM: Ideally we could get this programmatically.
+		 */
+		long sys_cacheline_size = CACHE_LINE_SIZE;
+#endif
 
 		if (sys_cacheline_size > 0)
 			cacheline_size = sys_cacheline_size;
