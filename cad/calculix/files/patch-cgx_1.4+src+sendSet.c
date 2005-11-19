--- cgx_1.4/src/sendSet.c.orig	Sun Oct 30 16:53:40 2005
+++ cgx_1.4/src/sendSet.c	Sun Oct 30 16:54:24 2005
@@ -965,7 +965,7 @@
   int   setNr;
   int  length, i,j;
   unsigned char prognam[MAX_LINE_LENGTH];
-  float *temp, *alpha;
+  static float *temp, *alpha;
   FILE *handle;
   int  n, lc, entity;
 
