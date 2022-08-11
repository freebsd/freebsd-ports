--- src/engine/server/databases/mysql.cpp.orig	2022-07-05 08:29:46 UTC
+++ src/engine/server/databases/mysql.cpp
@@ -11,7 +11,6 @@
 #include <vector>
 
 #ifndef LIBMARIADB
-typedef bool my_bool;
 #endif
 
 enum
