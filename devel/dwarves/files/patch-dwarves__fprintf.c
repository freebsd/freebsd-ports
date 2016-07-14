--- dwarves_fprintf.c.orig	2012-03-20 16:18:48 UTC
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
@@ -74,7 +77,6 @@ static const char *dwarf_tag_names[] = {
 	[DW_TAG_unspecified_type]	  = "unspecified_type",
 	[DW_TAG_partial_unit]		  = "partial_unit",
 	[DW_TAG_imported_unit]		  = "imported_unit",
-	[DW_TAG_mutable_type]		  = "mutable_type",
 	[DW_TAG_condition]		  = "condition",
 	[DW_TAG_shared_type]		  = "shared_type",
 #ifdef STB_GNU_UNIQUE
@@ -1664,7 +1666,14 @@ void cus__print_error_msg(const char *pr
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
