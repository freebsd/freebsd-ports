--- gr-radio-astronomy/src/python/usrp_psr_receiver.py.orig	Thu Mar  1 15:18:36 2007
+++ gr-radio-astronomy/src/python/usrp_psr_receiver.py	Thu Mar  1 15:19:57 2007
@@ -95,7 +95,7 @@
         self.reflevel = options.reflevel
         self.divbase = options.divbase
         self.division = options.division
-        self.audiodev = options.audio_dev
+        self.audiodev = options.audio_source
 
         # Low-pass cutoff for post-detector filter
         # Set to 100Hz usually, since lots of pulsars fit in this
