--- ui.c.orig	Sun Jan  4 15:42:01 2004
+++ ui.c	Thu Oct 14 23:20:27 2004
@@ -284,7 +284,7 @@
     XGlyphInfo      extents;
     char            str1[100];
     char           *ps, *ps1;
-    int             l1, l2;
+    size_t          l1, l2;
 
     if (!xftFont)
 	return 0;
@@ -294,7 +294,7 @@
     ps = str1;
     ps1 = str;
 
-    l1 = iconv (convUTF8, (char **) &str, &l1, &ps, &l2);
+    l1 = iconv (convUTF8, (const char **) &str, &l1, &ps, &l2);
     *ps = '\0';
     XftTextExtentsUtf8 (dpy, xftFont, str1, strlen (str1), &extents);
     return extents.width;
@@ -323,7 +323,7 @@
 void OutputString (Window window, char *str, int x, int y, XColor color)
 {
     char            strOutput[100] = "";	//该长度应该够用了
-    int             l1, l2;
+    size_t          l1, l2;
     char           *ps;
     XftColor        xftColor;
     XRenderColor    renderColor;
@@ -339,7 +339,7 @@
     l2 = 99;
     ps = strOutput;
 
-    l1 = iconv (convUTF8, (char **) (&str), &l1, &ps, &l2);
+    l1 = iconv (convUTF8, (const char **) (&str), &l1, &ps, &l2);
 
     renderColor.red = color.red;
     renderColor.green = color.green;
