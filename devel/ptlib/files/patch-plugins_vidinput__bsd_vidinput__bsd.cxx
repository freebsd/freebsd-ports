--- plugins/vidinput_bsd/vidinput_bsd.cxx.orig	2013-08-14 23:20:28 UTC
+++ plugins/vidinput_bsd/vidinput_bsd.cxx
@@ -308,7 +308,7 @@ PBoolean PVideoInputDevice_BSDCAPTURE::G
 
     mmap_size = frameBytes;
     videoBuffer = (BYTE *)::mmap(0, mmap_size, PROT_READ, 0, videoFd, 0);
-    if (videoBuffer < 0) {
+    if (videoBuffer == MAP_FAILED) {
       return PFalse;
     } else {
       canMap = 1;
