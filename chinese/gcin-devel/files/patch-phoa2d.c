--- phoa2d.c.orig	Thu Jul 29 03:15:13 2004
+++ phoa2d.c	Thu Jul 29 03:15:20 2004
@@ -77,8 +77,6 @@
   FILE *fp;
   char s[64];
 
-  gtk_init(&argc, &argv);
-
   if ((fp=fopen(fname,"r"))==NULL)
     p_err("cannot open %s\n", fname);
 
@@ -159,6 +157,5 @@
 
   fclose(fp);
 
-  send_gcin_message(GDK_DISPLAY(), "reload");
   return 0;
 }
