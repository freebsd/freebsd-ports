--- xvinfo.c.orig	1994-12-22 22:34:41 UTC
+++ xvinfo.c
@@ -26,7 +26,7 @@
 #define INFOHIGH 270
 
 /* max length of an Info String */
-#define ISTRLEN 80
+#define ISTRLEN 256
 
 /* baseline of top line of text */
 #define TOPBASE (36 + penn_height/2 + 4 + 8 + ASCENT)
