--- src/init.c.orig	1999-08-08 05:56:11.000000000 +0400
+++ src/init.c	2015-01-12 20:23:12.000000000 +0300
@@ -250,6 +250,7 @@
    if (color_term != -1)
    {
       start_color ();
+      use_default_colors();
       if ((color_term = has_colors ()))
       {
          color_term = 1;
