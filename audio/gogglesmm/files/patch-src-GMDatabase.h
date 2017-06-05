--- src/GMDatabase.h.orig	2017-03-29 02:18:22 UTC
+++ src/GMDatabase.h
@@ -21,7 +21,7 @@
 
 struct sqlite3_stmt;
 struct sqlite3;
-typedef struct Mem sqlite3_value;
+typedef struct sqlite3_value sqlite3_value;
 struct sqlite3_context;
 
 
