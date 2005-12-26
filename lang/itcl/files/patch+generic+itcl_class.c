--- generic/itcl_class.c.orig	Mon May 21 20:35:38 2001
+++ generic/itcl_class.c	Sun Dec 25 15:28:16 2005
@@ -732,7 +732,7 @@
         /* flags */ 0);
 
     if ( !classNs && contextNs->parentPtr != NULL &&
-         (*path != ':' || *(path+1) != ':') ) {
+         (strncmp(path, "::", 2) != 0) ) {
 
         if (strcmp(contextNs->name, path) == 0) {
             classNs = contextNs;
