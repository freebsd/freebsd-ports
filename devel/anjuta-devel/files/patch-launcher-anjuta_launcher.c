--- launcher/anjuta_launcher.c.orig	Sun Aug 12 11:37:07 2001
+++ launcher/anjuta_launcher.c	Sun Aug 12 11:37:15 2001
@@ -22,7 +22,7 @@
 #endif
 
 #include <sys/types.h>
-#include <sys/unistd.h>
+#include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
 #include <glib.h>
