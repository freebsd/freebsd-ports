--- InputWindow.c.orig	Tue Dec 30 15:54:47 2003
+++ InputWindow.c	Thu Oct 14 23:18:49 2004
@@ -110,7 +110,7 @@
     char            str1[] = "Ay÷–";
     char            str2[10];
     char           *ps1, *ps2;
-    int             l1, l2;
+    size_t          l1, l2;
 
     if (!xftFont)
 	return;
@@ -120,7 +120,7 @@
     ps2 = str2;
     ps1 = str1;
 
-    l1 = iconv (convUTF8, (char **) &ps1, &l1, &ps2, &l2);
+    l1 = iconv (convUTF8, (const char **) &ps1, &l1, &ps2, &l2);
 
     XftTextExtentsUtf8 (dpy, xftFont, str2, strlen (str2), &extents);
     iInputWindowHeight = extents.height * 2 + extents.height / 2 + 8;
