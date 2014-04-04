--- ./src/gtkballs.c.orig	2004-02-06 14:51:54.000000000 +0100
+++ ./src/gtkballs.c	2014-03-30 20:05:17.338033553 +0200
@@ -123,7 +123,7 @@
 #ifdef ENABLE_NLS
   	bindtextdomain (PACKAGE, LOCALEDIR);
   	textdomain (PACKAGE);
-        bind_textdomain_codeset(PACKAGE, "UTF8");
+        bind_textdomain_codeset(PACKAGE, "UTF-8");
 #endif /* ENABLE_NLS */
 
         /* drop privileges after spawning child with extra privs */
