--- game/main.cpp.orig	2005-09-12 04:04:52.000000000 +0200
+++ game/main.cpp	2012-05-11 17:51:11.000000000 +0200
@@ -27,6 +27,7 @@
 
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <zlib.h>
 
 void migrateConfig( void)
 {
