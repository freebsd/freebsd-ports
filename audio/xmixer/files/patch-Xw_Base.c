--- Xw/Base.c.orig	1999-02-05 16:30:23 UTC
+++ Xw/Base.c
@@ -89,8 +89,8 @@ static XtActionsRec actions [] = {
  * default translation table
  */
 static char defaultTranslations [] = "\
-<FocusIn>: focus(in)
-<FocusOut>: focus(out)
+<FocusIn>: focus(in)\n\
+<FocusOut>: focus(out)\n\
 <Key>Tab:	tab()";
 
 /*
