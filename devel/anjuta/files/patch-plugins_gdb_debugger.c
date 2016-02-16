--- plugins/gdb/debugger.c.orig	2015-09-20 09:01:33.000000000 +0200
+++ plugins/gdb/debugger.c	2015-10-19 17:22:53.852510000 +0200
@@ -56,7 +56,7 @@
 
 #define GDB_PROMPT  "(gdb)"
 #define FILE_BUFFER_SIZE 1024
-#define GDB_PATH "gdb"
+#define GDB_PATH "%%LOCALBASE%%/bin/gdb"
 #define MAX_CHILDREN		25		/* Limit the number of variable children
 									 * returned by debugger */
 #define SUMMARY_MAX_LENGTH   90	 /* Should be smaller than 4K to be displayed
