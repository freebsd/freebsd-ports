--- plugins/vidinput_v4l/vidinput_v4l.cxx.orig	2013-08-14 23:20:28 UTC
+++ plugins/vidinput_v4l/vidinput_v4l.cxx
@@ -978,7 +978,7 @@ PBoolean PVideoInputDevice_V4L::GetFrame
     } else {
       videoBuffer = (BYTE *)::mmap(0, frame.size, PROT_READ|PROT_WRITE, MAP_SHARED, videoFd, 0);
      
-      if (videoBuffer < 0) {
+      if (videoBuffer == MAP_FAILED) {
         canMap = 0;
         PTRACE(3, "VideoGrabber " << deviceName << " cannot do memory mapping - ::mmap failed.");
         //This video device cannot do memory mapping.
