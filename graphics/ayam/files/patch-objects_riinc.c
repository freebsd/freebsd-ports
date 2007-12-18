--- objects/riinc.c.orig	2007-12-17 18:40:30.000000000 +0100
+++ objects/riinc.c	2007-12-17 18:40:55.000000000 +0100
@@ -165,7 +165,7 @@
  char *n1 = "RiIncAttrData";
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  ay_riinc_object *riinc = NULL;
- char *result = NULL;
+ const char *result;
 
   if(!o)
     return AY_ENULL;
