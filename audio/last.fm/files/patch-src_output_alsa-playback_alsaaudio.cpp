--- src/output/alsa-playback/alsaaudio.cpp.orig	2016-07-26 15:06:09 UTC
+++ src/output/alsa-playback/alsaaudio.cpp
@@ -798,8 +798,6 @@ int AlsaAudio::alsa_handle_error( int er
     {
         case -EPIPE:
             return xrun_recover();
-        case -ESTRPIPE:
-            return suspend_recover();
     }
 
     return err;
