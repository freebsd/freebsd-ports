
$FreeBSD$

--- src/common.h	2002/06/01 21:08:46	1.1
+++ src/common.h	2002/06/01 21:09:16
@@ -152,6 +152,9 @@
 /* Patterns that match file names to be excluded.  */
 GLOBAL struct exclude *excluded;
 
+/* Boolean value.  */
+GLOBAL int fast_read_option;
+
 /* Specified file containing names to work on.  */
 GLOBAL const char *files_from_option;
 
@@ -195,6 +198,9 @@
 
 /* Boolean value.  */
 GLOBAL int multi_volume_option;
+
+/* Boolean value.  */
+GLOBAL int namelist_freed;
 
 /* The same variable hold the time, whether mtime or ctime.  Just fake a
    non-existing option, for making the code clearer, elsewhere.  */
