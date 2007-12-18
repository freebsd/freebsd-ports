--- objects/root.c.orig	2007-12-17 18:43:32.000000000 +0100
+++ objects/root.c	2007-12-17 18:44:08.000000000 +0100
@@ -186,7 +186,7 @@
  ay_riopt *riopt = NULL;
  double dtemp = 0.0;
  int itemp = 0;
- char *result;
+ const char *result;
 
   if(!o)
     return AY_ENULL;
