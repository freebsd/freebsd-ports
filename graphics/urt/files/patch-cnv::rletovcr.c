--- cnv/rletovcr.c.orig	Thu Mar 10 20:17:23 2005
+++ cnv/rletovcr.c	Thu Mar 10 20:20:49 2005
@@ -83,11 +83,10 @@
 static char COMMENT[80];   /* comment! */
 #endif
     
-WriteVICARHeader(fd, width, height, BandsPerPixel)
+void WriteVICARHeader(fd, width, height, BandsPerPixel)
 FILE *fd;
 int width, height, BandsPerPixel;
 {
-    int pad;
     char *buffer, *bp;
 
     /*
@@ -254,7 +253,7 @@
 int argc;
 char *argv[];
 {
-    char *infname = NULL, outfname = NULL;
+    char *infname = NULL, *outfname = NULL;
     int oflag = 0;
     unsigned char *VICARImage;
     rle_hdr the_hdr;
