--- src/gtkballs.c.orig	2004-02-06 13:51:54 UTC
+++ src/gtkballs.c
@@ -123,7 +123,7 @@ int main(int argc, char **argv) {
 #ifdef ENABLE_NLS
   	bindtextdomain (PACKAGE, LOCALEDIR);
   	textdomain (PACKAGE);
-        bind_textdomain_codeset(PACKAGE, "UTF8");
+        bind_textdomain_codeset(PACKAGE, "UTF-8");
 #endif /* ENABLE_NLS */
 
         /* drop privileges after spawning child with extra privs */
