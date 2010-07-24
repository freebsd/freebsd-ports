--- vidio/vidio.cc.orig	2009-06-10 00:32:20.000000000 +0200
+++ vidio/vidio.cc	2010-07-11 10:29:54.176325026 +0200
@@ -27,7 +27,6 @@
 extern "C" {
 #include <assert.h>
 #include <math.h>
-#include <malloc.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
@@ -119,7 +118,7 @@
                              AVStream *st);
         void closeOutputVideo(AVFormatContext *oc, 
                               AVStream *st);
-        AVFrame *allocOutputPicture(int pix_fmt, int width, int height);
+        AVFrame *allocOutputPicture(PixelFormat pix_fmt, int width, int height);
 
         void copyToYUV(bytearray &red,
                        bytearray &green,
@@ -624,7 +623,7 @@
 
 
 
-    AVFrame *VidOutImpl::allocOutputPicture(int pix_fmt, int width, int height) {
+    AVFrame *VidOutImpl::allocOutputPicture(PixelFormat pix_fmt, int width, int height) {
 
         AVFrame *picture;
         uint8_t *picture_buf;
