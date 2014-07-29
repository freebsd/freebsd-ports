--- x11/xdata.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ x11/xdata.cpp	2012-05-27 06:52:59.000000000 +0900
@@ -1,4 +1,5 @@
 /* 
+ * WK - note to self - search for xpmcreate
  * XEvil(TM) Copyright (C) 1994,2000 Steve Hardt and Michael Judge
  * http://www.xevil.com
  * satan@xevil.com
@@ -30,11 +31,12 @@
 #include "xdata.h"
 #include "area.h"
 
-#include <iostream.h>
+#include <iostream>
 #include <X11/Xutil.h>
 #include <X11/xpm.h>
 #include <X11/Xatom.h>
 
+using namespace std;
 
 
 // Means always allocate some color, even if it's really, really bad.
@@ -47,9 +49,16 @@
                                      int dpyNum,const Size& size,
                                      const char* title,
                                      long eventMask) {
+
+  // Get Size of screen, so we can center Window
+  XWindowAttributes root_window_attributes;
+  XGetWindowAttributes(dpy[dpyNum],root[dpyNum], &root_window_attributes);
+  int left = (root_window_attributes.width - size.width) / 2;
+  int top = (root_window_attributes.height - size.height) / 3;
+
   // Creates with 0 border width.
   Window toplevel = 
-    XCreateSimpleWindow(dpy[dpyNum],root[dpyNum],0,0,
+    XCreateSimpleWindow(dpy[dpyNum],root[dpyNum],left,top,
                         size.width,size.height,
                         0,windowBorder[dpyNum],
                         windowBg[dpyNum]);
@@ -90,7 +99,9 @@
 
   XClassHint class_hints;
   class_hints.res_name = argv[0];
-  class_hints.res_class = "XEvil";
+
+  static char res_class[] = "XEvil";
+  class_hints.res_class = res_class;
 
   XSetWMProperties(dpy[dpyNum],toplevel,
                    &windowName,&iconName,argv,argc,
@@ -185,14 +196,14 @@
 
 
 Boolean Xvars::load_pixmap(Drawable* pixmap,Drawable* mask,
-                           int dpyNum,char** xpmBits) {
+                           int dpyNum, const char** xpmBits) {
   return load_pixmap(pixmap,mask,dpyNum,xpmBits,is_stretched());
 }
 
 
 
 Boolean Xvars::load_pixmap(Drawable* pixmap,Drawable* mask,
-                           int dpyNum,char** xpmBits,Boolean fullSize) {
+                           int dpyNum, const char** xpmBits,Boolean fullSize) {
   // Just load XPM as is.
   if (fullSize) {
     XpmAttributes attr;
@@ -200,9 +211,9 @@
     attr.closeness = XPM_CLOSENESS;
     attr.alloc_close_colors = True;
 
-    int val = 
+  int val = 
       XpmCreatePixmapFromData(dpy[dpyNum],root[dpyNum],
-                              xpmBits,
+                              const_cast<char **> (xpmBits),
                               pixmap,mask,
                               &attr);
     XpmFreeAttributes(&attr);
@@ -212,7 +223,7 @@
       ret = False;
     }
 
-    return ret; 
+    return ret;
   }
 
 
@@ -231,9 +242,8 @@
 
   // Perhaps should use XpmReturnAllocPixels, neither gives the transparent 
   // value.
-  int val = 
-    XpmCreateImageFromData(dpy[dpyNum],
-                           xpmBits,
+  int val = XpmCreateImageFromData(dpy[dpyNum],
+                           const_cast<char **> (xpmBits),
                            &srcImage,(mask ? &srcMask : (XImage**)NULL),
                            &attr);
   srcSize.width = attr.width;
