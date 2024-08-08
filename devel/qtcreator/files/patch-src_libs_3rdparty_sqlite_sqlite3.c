--- src/libs/3rdparty/sqlite/sqlite3.c.orig	2024-05-31 12:46:31 UTC
+++ src/libs/3rdparty/sqlite/sqlite3.c
@@ -13857,7 +13857,7 @@ struct fts5_api {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE)
 #  define _XOPEN_SOURCE 600
 #endif
 
