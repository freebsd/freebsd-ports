--- objects/text.c.orig	2016-01-13 20:09:57 UTC
+++ objects/text.c
@@ -274,7 +274,7 @@ ay_text_setpropcb(Tcl_Interp *interp, in
  /*int ay_status = AY_OK;*/
  char fname[] = "setProp";
  char *n1 = "TextAttrData";
- char *result;
+ const char *result;
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  ay_text_object *text = NULL;
  Tcl_UniChar *unistr = NULL;
