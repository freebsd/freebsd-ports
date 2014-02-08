--- ./fotoxx.h.orig	2014-02-05 20:42:34.000000000 +0100
+++ ./fotoxx.h	2014-02-06 10:32:37.000000000 +0100
@@ -339,8 +339,8 @@
 EX int         dww, dhh;                                                   //  Dpxb size in drawing window, <= Dww, Dhh
 EX int         zoomx, zoomy;                                               //  req. zoom center of window
 
-EX mutex       Fpixmap_lock;                                               //  lock for accessing PXM pixmaps
-EX mutex       preload_lock;                                               //  lock for image file preload function
+EX mutex_tp    Fpixmap_lock;                                               //  lock for accessing PXM pixmaps
+EX mutex_tp    preload_lock;                                               //  lock for image file preload function
 
 EX int         Mbutton;                                                    //  mouse button, 1/3 = left/right
 EX int         Mwxposn, Mwyposn;                                           //  mouse position, window space
