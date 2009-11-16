--- src/gtkballs.c.orig	2009-11-16 23:08:02.000000000 +0100
+++ src/gtkballs.c	2009-11-16 23:08:12.000000000 +0100
@@ -123,7 +123,7 @@ int main(int argc, char **argv) {
 #ifdef ENABLE_NLS
   	bindtextdomain (PACKAGE, LOCALEDIR);
   	textdomain (PACKAGE);
-        bind_textdomain_codeset(PACKAGE, "UTF8");
+        bind_textdomain_codeset(PACKAGE, "UTF-8");
 #endif /* ENABLE_NLS */
 
         /* drop privileges after spawning child with extra privs */
