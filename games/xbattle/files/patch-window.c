--- ./window.c.orig	1995-12-19 23:21:51.000000000 +0100
+++ ./window.c	2014-03-29 18:28:42.009953797 +0100
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <string.h>
+#include <stdlib.h>
 
 #include "constant.h"
   
@@ -708,8 +710,7 @@
   unsigned long valuemask;
   XSetWindowAttributes attrib;
   XVisualInfo vinfo;
-  long event_mask,
-       full_depth;
+  long event_mask;
   Atom wm_delete_window;
 
   /** Open display and screen **/
@@ -742,36 +743,11 @@
   /** Set bitplane depth to default **/
 
   xwindow->depth = DefaultDepth (xwindow->display, xwindow->screen);
-  full_depth = xwindow->depth;
 
   /** Get a visual **/
 
   visual = DefaultVisual (xwindow->display, xwindow->screen);
 
-  /** Try to force the display to 8 planes **/
-
-  if (xwindow->depth != 8)
-  {
-    if (XMatchVisualInfo
-		(xwindow->display, xwindow->screen, 8, PseudoColor, &vinfo))
-    {
-      visual = vinfo.visual;
-      xwindow->depth = 8;
-    }
-  }
-
-  /** If couldn't find an 8 bit visual, try a 16 bit visual **/
-
-  if (xwindow->depth != 8)
-  {
-    if (XMatchVisualInfo
-		(xwindow->display, xwindow->screen, 16, PseudoColor, &vinfo))
-    {
-      visual = vinfo.visual;
-      xwindow->depth = 16;
-    }
-  }
-
   /** If have less than 8 planes, just use a single plane **/
 
   if (xwindow->depth < 8)
@@ -790,19 +766,8 @@
 #else
     /** Allocate existing colormap **/
 
-    if (full_depth > 8)
+    if (xwindow->depth > 8)
     {
-      /** XBattle won't work for 24 bit displays with no optional	**/
-      /** visuals with 8 or 16 bits.  This may be the case on some PCs.	**/
-      /** In these cases, it may be possible to reconfigure the display	**/
-      /** to 8 or 16 bits.						**/
-
-      if (xwindow->depth > 16)
-      {
-        throw_warning ("No PseudoColor visual available\n%s",
-		"         Try changing display to <= 16 bits");
-        throw_error ("Unable to continue without colormap", NULL);
-      }
 
       /** If display is 24 bit, have to create a dedicated colormap **/
 
