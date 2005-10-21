--- zoom.c.orig	Thu Oct 13 04:42:36 2005
+++ zoom.c	Thu Oct 13 04:43:47 2005
@@ -52,26 +52,26 @@
     if (verbose)
       printf("  Zooming image Y axis by %d%%...", yzoom);
     if (changetitle)
-      sprintf(buf, "%s (Y zoom %d%%)", oimage->title, yzoom);
+      snprintf(buf, sizeof(buf), "%s (Y zoom %d%%)", oimage->title, yzoom);
   }
   else if (!yzoom) {
     if (verbose)
       printf("  Zooming image X axis by %d%%...", xzoom);
     if (changetitle)
-      sprintf(buf, "%s (X zoom %d%%)", oimage->title, xzoom);
+      snprintf(buf, sizeof(buf), "%s (X zoom %d%%)", oimage->title, xzoom);
   }
   else if (xzoom == yzoom) {
     if (verbose)
       printf("  Zooming image by %d%%...", xzoom);
     if (changetitle)
-      sprintf(buf, "%s (%d%% zoom)", oimage->title, xzoom);
+      snprintf(buf, sizeof(buf), "%s (%d%% zoom)", oimage->title, xzoom);
   }
   else {
     if (verbose)
       printf("  Zooming image X axis by %d%% and Y axis by %d%%...",
 	     xzoom, yzoom);
     if (changetitle)
-      sprintf(buf, "%s (X zoom %d%% Y zoom %d%%)", oimage->title,
+      snprintf(buf, sizeof(buf), "%s (X zoom %d%% Y zoom %d%%)", oimage->title,
 	    xzoom, yzoom);
   }
   if (!changetitle)
