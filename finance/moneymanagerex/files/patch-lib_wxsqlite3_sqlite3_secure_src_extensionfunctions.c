--- lib/wxsqlite3/sqlite3/secure/src/extensionfunctions.c.orig	2015-03-03 21:30:22 UTC
+++ lib/wxsqlite3/sqlite3/secure/src/extensionfunctions.c
@@ -208,9 +208,9 @@ int double_cmp(const void *a, const void
 
 #endif /* _MAP_H_ */
 
-typedef uint8_t         u8;
+//typedef uint8_t         u8;
 //typedef uint16_t        u16;
-typedef int64_t         i64;
+//typedef int64_t         i64;
 
 static char *sqlite3StrDup( const char *z ) {
     char *res = sqlite3_malloc( strlen(z)+1 );
