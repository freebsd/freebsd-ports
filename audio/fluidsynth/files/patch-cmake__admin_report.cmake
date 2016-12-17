--- cmake_admin/report.cmake.orig	2012-08-16 04:01:13 UTC
+++ cmake_admin/report.cmake
@@ -25,6 +25,12 @@ else ( PULSE_SUPPORT ) 
   message ( "PulseAudio:            no" )
 endif ( PULSE_SUPPORT )
 
+if ( SNDIO_SUPPORT )
+  message ( "Sndio:                 yes" )
+else ( SNDIO_SUPPORT )
+  message ( "Sndio:                 no" )
+endif ( SNDIO_SUPPORT )
+
 if ( JACK_SUPPORT )
   message ( "JACK:                  yes" )
 else ( JACK_SUPPORT )
