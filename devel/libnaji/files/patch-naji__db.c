--- naji_db.c.orig	2011-09-03 05:33:13 UTC
+++ naji_db.c
@@ -20,7 +20,7 @@
 
 #include "libnaji.h"
 
-char buffer[306];
+static char buffer[306];
 
 FILE *naji_db_file;
 
