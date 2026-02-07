--- blocks.c.orig	2004-01-22 13:58:26 UTC
+++ blocks.c
@@ -32,7 +32,6 @@
 #endif
 
 extern List *blocks;
-extern void warnFor(Token*, char*, char*);
 
 Blox *pushBlock(Token *cmd, int infl, int lvl, int cond)
 {
