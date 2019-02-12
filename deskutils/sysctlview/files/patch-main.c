--- main.c.orig	2018-12-26 11:57:59 UTC
+++ main.c
@@ -27,7 +27,7 @@
 
 #include "trees.h"
 
-#define DATADIR "./"
+#define DATADIR "%%PREFIX%%/share/sysctlview/"
 
 int
 main (int argc, char *argv[])
