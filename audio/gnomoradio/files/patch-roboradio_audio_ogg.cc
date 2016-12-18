--- roboradio/audio/ogg.cc.orig	2004-11-06 21:55:32 UTC
+++ roboradio/audio/ogg.cc
@@ -25,6 +25,7 @@
 
 #include <string>
 #include <algorithm>
+#include <cstring>
 
 #include <iostream>
 
@@ -193,6 +194,7 @@ void Roboradio::Audio::Ogg::thread_funct
 
 	int device_id = ao_default_driver_id();
 	ao_sample_format output_fmt;
+	memset(&output_fmt, 0, sizeof(output_fmt));
 	output_fmt.bits = 16;
 	output_fmt.rate = 44100;
 	output_fmt.channels = 2;
