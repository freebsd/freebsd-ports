--- src/conf.c	Tue Aug 26 07:54:35 2003
+++ src/conf.c.patch	Mon May 24 16:57:43 2004
@@ -798,6 +798,7 @@
   if (!fp)
     {
       g_warning ("Can't open the printing configuration file.");
+      return;
     }
 
   fprintf (fp, "font_family = %s\n", encode_font (PConf->font_family));
