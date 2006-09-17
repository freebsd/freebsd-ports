--- window_x11.c.orig	Sun Sep  3 16:44:07 2006
+++ window_x11.c	Sun Sep  3 16:44:16 2006
@@ -354,9 +354,9 @@
     /*
     **  Load three Cyber fonts.
     */
-    hSmallFont = XLoadFont(disp, "-*-lucidatypewriter-medium-*-*-*-10-*-*-*-*-*-*-*\0");
-    hMediumFont = XLoadFont(disp, "-*-lucidatypewriter-medium-*-*-*-14-*-*-*-*-*-*-*\0");
-    hLargeFont = XLoadFont(disp, "-*-lucidatypewriter-medium-*-*-*-24-*-*-*-*-*-*-*\0");
+    hSmallFont = XLoadFont(disp, "-*-fixed-medium-*-*-*-10-*-*-*-*-*-*-*\0");
+    hMediumFont = XLoadFont(disp, "-*-fixed-medium-*-*-*-14-*-*-*-*-*-*-*\0");
+    hLargeFont = XLoadFont(disp, "-*-fixed-medium-*-*-*-24-*-*-*-*-*-*-*\0");
 
     /*
     **  Setup fore- and back-ground colors.
