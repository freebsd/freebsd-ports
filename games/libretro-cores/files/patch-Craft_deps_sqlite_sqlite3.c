--- Craft/deps/sqlite/sqlite3.c.orig	2016-10-21 03:09:13 UTC
+++ Craft/deps/sqlite/sqlite3.c
@@ -17,6 +17,9 @@
 ** language. The code for the "sqlite3" command-line shell is also in a
 ** separate file. This file contains only code for the core SQLite library.
 */
+
+#include <sys/stat.h>
+
 #define SQLITE_CORE 1
 #define SQLITE_AMALGAMATION 1
 #ifndef SQLITE_PRIVATE
@@ -2330,7 +2333,6 @@ struct sqlite3_mem_methods {
 #define SQLITE_DBCONFIG_ENABLE_FKEY     1002  /* int int* */
 #define SQLITE_DBCONFIG_ENABLE_TRIGGER  1003  /* int int* */
 
-
 /*
 ** CAPI3REF: Enable Or Disable Extended Result Codes
 **
