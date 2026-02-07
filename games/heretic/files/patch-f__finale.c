--- f_finale.c.orig	2000-01-22 15:22:45 UTC
+++ f_finale.c
@@ -22,7 +22,7 @@ char    *e5text = E5TEXT;
 char    *finaletext;
 char    *finaleflat;
 
-int FontABaseLump;
+extern int FontABaseLump;
 
 extern boolean automapactive;
 extern boolean viewactive;
