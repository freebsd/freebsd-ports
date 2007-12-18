--- objects/view.c.orig	2007-12-17 18:47:07.000000000 +0100
+++ objects/view.c	2007-12-17 18:47:21.000000000 +0100
@@ -167,7 +167,7 @@
  char *n1 = "CameraData", *n2 = "ViewAttribData";
  Tcl_Obj *to = NULL, *toa = NULL, *ton = NULL;
  int itemp = 0;
- char *result;
+ const char *result;
  char fname[] = "view_setpropcb";
 
   if(!o)
