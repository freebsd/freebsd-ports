--- src/ui.c.orig	Wed Feb 23 03:34:39 2005
+++ src/ui.c	Wed Mar  2 09:53:26 2005
@@ -361,7 +361,7 @@
     l2 = 99;
     ps = str1;
 
-    l1 = iconv (convUTF8, &str, &l1, &ps, &l2);
+    l1 = iconv (convUTF8, (const char**) &str, &l1, &ps, &l2);
     *ps = '\0';
     XftTextExtentsUtf8 (dpy, font, (FcChar8 *) str1, strlen (str1), &extents);
     if (font == xftMainWindowFont)
@@ -386,7 +386,7 @@
     ps2 = str2;
     ps1 = str1;
 
-    l1 = iconv (convUTF8, &ps1, &l1, &ps2, &l2);
+    l1 = iconv (convUTF8, (const char**) &ps1, &l1, &ps2, &l2);
     *ps2 = '\0';
 
     XftTextExtentsUtf8 (dpy, font, (FcChar8 *) str2, strlen (str2), &extents);
@@ -439,7 +439,7 @@
     l1 = strlen (str);
     l2 = 99;
     ps = strOutput;
-    l1 = iconv (convUTF8, &str, &l1, &ps, &l2);
+    l1 = iconv (convUTF8, (const char**) &str, &l1, &ps, &l2);
     *ps = '\0';
 
     renderColor.red = color.red;
