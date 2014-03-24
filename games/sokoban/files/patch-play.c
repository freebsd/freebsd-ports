--- ./play.c.orig	1992-05-16 02:53:27.000000000 -0400
+++ ./play.c	2014-03-11 22:14:36.546748659 -0400
@@ -37,7 +37,7 @@
 
 short play() {
 
-   short c;
+   char c;
    short ret;
    short undolock = 1;		/* locked for undo */
 
