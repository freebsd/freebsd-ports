--- src/command.c.orig	Fri Oct 25 12:57:17 2002
+++ src/command.c	Sat Apr  5 09:16:50 2003
@@ -1755,10 +1755,6 @@
         setlocale(LC_ALL, "");
         fontset = XCreateFontSet(Xdisplay, fontname, &ml, &mc, &ds);
         FREE(fontname);
-        if (mc) {
-            XFreeStringList(ml);
-            fontset = 0;
-        }
     }
     return fontset;
 }
