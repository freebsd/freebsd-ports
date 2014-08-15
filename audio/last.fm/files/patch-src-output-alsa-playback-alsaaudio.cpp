--- src/output/alsa-playback/alsaaudio.cpp.orig	2014-08-15 14:23:25.000000000 +0200
+++ src/output/alsa-playback/alsaaudio.cpp	2014-08-15 16:29:32.000000000 +0200
@@ -798,8 +798,6 @@
     {
         case -EPIPE:
             return xrun_recover();
-        case -ESTRPIPE:
-            return suspend_recover();
     }
 
     return err;
