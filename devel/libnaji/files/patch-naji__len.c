--- naji_len.c.orig	2011-09-03 05:33:13 UTC
+++ naji_len.c
@@ -21,7 +21,7 @@
 #include "libnaji.h"
 
 
-char buffer[1024];
+static char buffer[1024];
 char *end;
 
 double meters=0;
