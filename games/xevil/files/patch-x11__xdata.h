--- x11/xdata.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ x11/xdata.h	2012-05-27 06:52:58.000000000 +0900
@@ -74,7 +74,7 @@
 
 typedef XEvent *CMN_EVENTDATA;
 
-typedef char *CMN_COLOR;
+typedef const char *CMN_COLOR;
 
 
 
@@ -132,14 +132,14 @@
      transformations.  Use scratch for all scratch calculations. */
 
   Boolean load_pixmap(Drawable* pixmap,Drawable* mask,
-                      int dpyNum,char** xpmBits);
+                      int dpyNum, const char** xpmBits);
   /* MODIFIES: pixmap, mask */
   /* EFFECTS: Load an XPM pixmap and mask from xpmBits.  Only load mask if 
      non-NULL.  Reduce pixmap size by a factor of 2 if 
      !xvars.is_stretched(). */
 
   Boolean load_pixmap(Drawable* pixmap,Drawable* mask,
-                      int dpyNum,char** xpmBits,Boolean fullSize);
+                      int dpyNum, const char** xpmBits,Boolean fullSize);
   /* EFFECTS: Same as above load_pixmap() except caller explicitly 
      specifies whether pixmap is fullSize or reduced by a factor of 2. */
   /* NOTE: This method can be called before Xvars::stretch is set. */
