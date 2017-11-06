--- src/gle/d_x.cpp.orig	2011-10-26 21:10:54 UTC
+++ src/gle/d_x.cpp
@@ -199,7 +199,7 @@ void X11GLEDevice::setfillstyle(int i) {
 #define BM_HEIGHT	16
 Pixmap bm;
 //unsigned
-const char bm_bits[][32] = {
+const unsigned char bm_bits[][32] = {
 {  0x00, 0x80, 0x00, 0x40, 0x00, 0x20, 0x00, 0x10, 0x00, 0x08, 0x00, 0x04,
    0x00, 0x02, 0x00, 0x01, 0x80, 0x00, 0x40, 0x00, 0x20, 0x00, 0x10, 0x00,
    0x08, 0x00, 0x04, 0x00, 0x02, 0x00, 0x01, 0x00},  /* SHADE    */
@@ -238,7 +238,7 @@ const char bm_bits[][32] = {
    0x1c, 0x38, 0x0e, 0x70, 0x07, 0xe0, 0x03, 0xc0}   /* GRID   5 */
 };
 
-    bm = XCreateBitmapFromData(dpy,window1,bm_bits[i],BM_WIDTH,BM_HEIGHT);
+    bm = XCreateBitmapFromData(dpy,window1,(const char*)bm_bits[i],BM_WIDTH,BM_HEIGHT);
     XSetStipple(dpy, gcf, bm);
     XSetFillStyle(dpy, gcf, FillStippled);
     XFreePixmap(dpy, bm);
