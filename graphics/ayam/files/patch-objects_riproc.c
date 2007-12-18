--- objects/riproc.c.orig	2007-12-17 18:41:21.000000000 +0100
+++ objects/riproc.c	2007-12-17 18:41:58.000000000 +0100
@@ -197,7 +197,7 @@
  char *n1 = "RiProcAttrData";
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  ay_riproc_object *riproc = NULL;
- char *result = NULL;
+ const char *result;
 
   if(!o)
     return AY_ENULL;
