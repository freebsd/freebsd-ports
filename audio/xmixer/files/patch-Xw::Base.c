--- Xw/Base.c.orig	Wed Jul 23 03:56:03 2003
+++ Xw/Base.c	Wed Jul 23 03:56:43 2003
@@ -89,8 +89,8 @@
  * default translation table
  */
 static char defaultTranslations [] = "\
-<FocusIn>: focus(in)
-<FocusOut>: focus(out)
+<FocusIn>: focus(in)\n\
+<FocusOut>: focus(out)\n\
 <Key>Tab:	tab()";
 
 /*
