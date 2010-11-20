--- plugins/gdb/debugger.c.orig	2010-07-25 22:27:28.000000000 +0200
+++ plugins/gdb/debugger.c	2010-09-01 12:00:35.000000000 +0200
@@ -56,7 +56,7 @@
 
 #define GDB_PROMPT  "(gdb)"
 #define FILE_BUFFER_SIZE 1024
-#define GDB_PATH "gdb"
+#define GDB_PATH "gdb66"
 #define MAX_CHILDREN		25		/* Limit the number of variable children
 									 * returned by debugger */
 #define SUMMARY_MAX_LENGTH   90	 /* Should be smaller than 4K to be displayed
