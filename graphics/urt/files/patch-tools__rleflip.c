--- tools/rleflip.c.orig	1992-01-24 01:45:49.000000000 +0900
+++ tools/rleflip.c	2012-10-15 22:53:02.000000000 +0900
@@ -44,7 +44,7 @@
 #define LEFT_FLAG  0x04
 #define RIGHT_FLAG 0x08
 
-void
+int
 main(argc, argv)
 int  argc;
 char *argv[];
