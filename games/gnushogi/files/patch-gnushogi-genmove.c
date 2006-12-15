--- gnushogi/genmove.c.orig	Fri Dec 15 00:14:06 2006
+++ gnushogi/genmove.c	Fri Dec 15 00:15:04 2006
@@ -40,7 +40,7 @@
 static short InCheck = false, GenerateAllMoves = false;
 static short check_determined = false;
 
-static short INCscore = 0;
+short INCscore = 0;
 
 short deepsearchcut = true;
 short tas = false, taxs = false, ssa = false;
