--- third_party/sqlite/src/amalgamation_dev/sqlite3.c.orig	2025-05-05 19:42:33 UTC
+++ third_party/sqlite/src/amalgamation_dev/sqlite3.c
@@ -14486,7 +14486,7 @@ struct fts5_api {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #  define _XOPEN_SOURCE 600
 #endif
 
