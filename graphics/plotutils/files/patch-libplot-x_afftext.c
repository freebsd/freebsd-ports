--- libplot/x_afftext.c.orig	2008-07-16 00:54:10 UTC
+++ libplot/x_afftext.c
@@ -185,7 +185,10 @@ XAffCreateAffinedText (Display *dpy, XFontStruct *font
   /* invert transformation matrix */
   det = aa[0] * aa[3] - aa[1] * aa[2];
   if (det == 0.0)
+  {
+    free(afftext);
     return NULL;		/* don't support singular matrices */
+  }
   a_inverse[0] =   aa[3] / det;
   a_inverse[1] = - aa[1] / det;
   a_inverse[2] = - aa[2] / det;
@@ -205,7 +208,10 @@ XAffCreateAffinedText (Display *dpy, XFontStruct *font
   
   /* paranoia */
   if (size_in.x == 0 || size_in.y == 0)
+  {
+    free(afftext);
     return NULL;
+  }
 
   /* work around a possible bug: some X displays can't create pixmaps that
      are only one pixel wide or high */
@@ -238,7 +244,10 @@ XAffCreateAffinedText (Display *dpy, XFontStruct *font
   /* create local image */
   im_in = XAffCreateXImage (dpy, size_in);
   if (im_in == NULL)
+  {
+    free(afftext);
     return NULL;
+  }
 
   /* copy bitmap to it */
   XGetSubImage (dpy, bitmap_in, 0, 0, size_in.x, size_in.y,
@@ -308,7 +317,10 @@ XAffCreateAffinedText (Display *dpy, XFontStruct *font
   /* create 2nd image, to hold affinely transformed text */
   im_out = XAffCreateXImage (dpy, size_out);
   if (im_out == NULL)
+  {
+    free(afftext);
     return NULL;
+  }
     
   /* copy from 1st image to this new one */
 
