--- objects/root.c.orig	2015-06-23 18:03:50 UTC
+++ objects/root.c
@@ -215,7 +215,7 @@ ay_root_setpropcb(Tcl_Interp *interp, in
  ay_riopt *riopt = NULL;
  double dtemp = 0.0;
  int itemp = 0;
- char *result;
+ const char *result;
 
   if(!interp || !o)
     return AY_ENULL;
