--- wmgeneral/wmgeneral.c.orig	2022-11-07 08:44:56 UTC
+++ wmgeneral/wmgeneral.c
@@ -55,6 +55,7 @@
  /* X11 Variables */
 /*****************/
 
+Display		*display;
 Window		Root;
 int			screen;
 int			x_fd;
