--- src/ui/ui.c.orig	Sun Nov 12 22:49:51 2006
+++ src/ui/ui.c	Wed Jul  4 22:43:49 2007
@@ -1207,7 +1207,7 @@
     )
 #endif
 #else
-			  "/usr/share/locale")
+			  PREFIX "/share/locale")
 #ifdef DEBUG
     )
 #endif
