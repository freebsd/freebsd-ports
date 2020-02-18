--- src/xfns.c.orig	2020-02-17 01:35:32 UTC
+++ src/xfns.c
@@ -2237,8 +2237,8 @@ static XIMStyle best_xim_style (XIMStyles *);
 
 static const XIMStyle supported_xim_styles[] =
 {
-  XIMPreeditPosition | XIMStatusArea,
   XIMPreeditPosition | XIMStatusNothing,
+  XIMPreeditPosition | XIMStatusArea,
   XIMPreeditPosition | XIMStatusNone,
   XIMPreeditNothing | XIMStatusArea,
   XIMPreeditNothing | XIMStatusNothing,
