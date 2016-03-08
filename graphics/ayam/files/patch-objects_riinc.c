--- objects/riinc.c.orig	2016-01-13 20:09:57 UTC
+++ objects/riinc.c
@@ -184,7 +184,7 @@ ay_riinc_setpropcb(Tcl_Interp *interp, i
  char *n1 = "RiIncAttrData";
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  ay_riinc_object *riinc = NULL;
- char *result = NULL;
+ const char *result;
 
   if(!interp || !o)
     return AY_ENULL;
