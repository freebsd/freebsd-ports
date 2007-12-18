--- objects/text.c.orig	2007-12-17 18:46:17.000000000 +0100
+++ objects/text.c	2007-12-17 18:46:39.000000000 +0100
@@ -164,7 +164,7 @@
  int ay_status = AY_OK;
  char fname[] = "setProp";
  char *n1 = "TextAttrData";
- char *result;
+ const char *result;
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  ay_text_object *text = NULL;
  Tcl_UniChar *unistr = NULL;
