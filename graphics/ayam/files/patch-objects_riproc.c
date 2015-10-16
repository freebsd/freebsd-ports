--- objects/riproc.c.orig	2015-06-23 18:03:50 UTC
+++ objects/riproc.c
@@ -197,7 +197,7 @@ ay_riproc_setpropcb(Tcl_Interp *interp, 
  char *n1 = "RiProcAttrData";
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  ay_riproc_object *riproc = NULL;
- char *result = NULL;
+ const char *result;
 
   if(!interp || !o)
     return AY_ENULL;
