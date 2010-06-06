
$FreeBSD$

--- roboradio/audio/ogg.cc.orig
+++ roboradio/audio/ogg.cc
@@ -193,6 +193,7 @@
 
 	int device_id = ao_default_driver_id();
 	ao_sample_format output_fmt;
+	memset(&output_fmt, 0, sizeof(output_fmt));
 	output_fmt.bits = 16;
 	output_fmt.rate = 44100;
 	output_fmt.channels = 2;
