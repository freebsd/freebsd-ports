--- src/libdisk/load_22dsk.c.orig	2010-03-07 20:50:22.000000000 +0100
+++ src/libdisk/load_22dsk.c	2013-12-15 14:43:31.000000000 +0100
@@ -81,7 +81,7 @@
 
 typedef struct {
   FILE *f;
-  gzFile *gzf;
+  gzFile gzf;
   int read_only;
   int len;
   struct {
