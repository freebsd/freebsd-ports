--- tsa2d.c.orig	Thu Jul 29 03:14:34 2004
+++ tsa2d.c	Thu Jul 29 03:14:46 2004
@@ -106,8 +106,6 @@
   int hashidx[256];
   u_char clen, llen;
 
-  gtk_init(&argc, &argv);
-
   if (argc > 1) {
     if ((fp=fopen(argv[1], "r"))==NULL) {
        printf("Cannot open %s\n", argv[1]);
@@ -300,6 +298,5 @@
 
   fclose(fw);
 
-  send_gcin_message(GDK_DISPLAY(), "reload");
   exit(0);
 }
