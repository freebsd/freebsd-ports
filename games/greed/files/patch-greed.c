--- greed.c.orig	2015-06-18 05:00:09 UTC
+++ greed.c
@@ -176,7 +176,6 @@ void showmoves(bool, int*);
 main(int argc, char **argv)
 {
     int val = 1;
-    extern long time();
     int attribs[9];
 #ifdef A_COLOR
     char *colors;
