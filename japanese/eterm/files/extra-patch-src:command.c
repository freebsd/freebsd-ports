--- src/command.c.orig	Sat Sep 15 16:57:02 2001
+++ src/command.c	Sat Sep 15 16:57:24 2001
@@ -1737,10 +1737,6 @@
     setlocale(LC_ALL, "");
     fontset = XCreateFontSet(Xdisplay, fontname, &ml, &mc, &ds);
     FREE(fontname);
-    if (mc) {
-      XFreeStringList(ml);
-      fontset = 0;
-    }
   }
   return fontset;
 }
