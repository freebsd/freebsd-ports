--- src/cairo-xlib-surface.c.orig	Mon Oct  3 22:44:43 2005
+++ src/cairo-xlib-surface.c	Wed Nov 16 18:59:40 2005
@@ -1758,7 +1758,7 @@
 
     surface->buggy_repeat = FALSE;
     if (strstr (ServerVendor (dpy), "X.Org") != NULL) {
-	if (VendorRelease (dpy) <= 60802000)
+	if (VendorRelease (dpy) < 60900000)
 	    surface->buggy_repeat = TRUE;
     } else if (strstr (ServerVendor (dpy), "XFree86") != NULL) {
 	if (VendorRelease (dpy) <= 40500000)
