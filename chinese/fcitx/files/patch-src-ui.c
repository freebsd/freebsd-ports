--- src/ui.c.orig	Wed Oct 27 23:19:07 2004
+++ src/ui.c	Wed Oct 27 23:20:59 2004
@@ -339,7 +339,7 @@
     l2 = 99;
     ps = str1;
 
-    l1 = iconv (convUTF8, &str, &l1, &ps, &l2);
+    l1 = iconv (convUTF8, (const char**) &str, &l1, &ps, &l2);
     *ps = '\0';
     XftTextExtentsUtf8 (dpy, font, (FcChar8*)str1, strlen (str1), &extents);
     if ( font!=xftFont)
@@ -364,7 +364,7 @@
     ps2 = str2;
     ps1 = str1;
 
-    l1 = iconv (convUTF8, &ps1, &l1, &ps2, &l2);
+    l1 = iconv (convUTF8, (const char**)&ps1, &l1, &ps2, &l2);
     *ps2='\0';
 
     XftTextExtentsUtf8 (dpy, font, (FcChar8 *)str2, strlen (str2), &extents);
@@ -418,7 +418,7 @@
     l2 = 99;
     ps = strOutput;
 
-    l1 = iconv (convUTF8, (char **) (&str), &l1, &ps, &l2);
+    l1 = iconv (convUTF8, (const char **) (&str), &l1, &ps, &l2);
     *ps='\0';
 
     renderColor.red = color.red;
