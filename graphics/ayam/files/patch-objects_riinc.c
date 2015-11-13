--- objects/riinc.c.orig	2015-06-23 18:03:50 UTC
+++ objects/riinc.c
@@ -184,7 +184,7 @@ ay_riinc_setpropcb(Tcl_Interp *interp, i
  char *n1 = "RiIncAttrData";
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  ay_riinc_object *riinc = NULL;
- char *result = NULL;
+ const char *result;
 
   if(!interp || !o)
     return AY_ENULL;
