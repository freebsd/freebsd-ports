--- ../wmgeneral/wmgeneral.c.orig	2020-12-21 11:20:47.205960000 -0600
+++ ../wmgeneral/wmgeneral.c	2020-12-21 11:21:15.735441000 -0600
@@ -51,6 +51,7 @@
 XpmIcon		wmgen;
 Pixmap		pixmask;
 
+Display		*display;
   /*****************/
  /* Mouse Regions */
 /*****************/
