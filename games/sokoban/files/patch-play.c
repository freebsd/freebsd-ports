--- play.c.orig	1992-05-16 06:53:27 UTC
+++ play.c
@@ -37,7 +37,7 @@ static POS   tmp_ppos;
 
 short play() {
 
-   short c;
+   char c;
    short ret;
    short undolock = 1;		/* locked for undo */
 
