--- src/imlib.c.orig	Sun Jan 13 15:03:52 2002
+++ src/imlib.c	Sat Jan 26 10:58:25 2002
@@ -34,6 +34,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
+#include <stdio.h>
 
 Display *disp = NULL;
 Visual *vis = NULL;
@@ -758,7 +759,7 @@
     feh_imlib_free_image(old);
     feh_reload_image(w, 1);
   } else {
-    wprintf("failed to load image from disk to edit it in place\n");
+    printf("failed to load image from disk to edit it in place\n");
   }
   
   D_RETURN_(4);
