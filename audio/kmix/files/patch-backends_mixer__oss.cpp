kmix assumes volume range 1:100 for oss mixer instead of 0:100.

See https://bugs.kde.org/344468
and https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=184996

--- backends/mixer_oss.cpp.orig	2014-07-16 08:24:17 UTC
+++ backends/mixer_oss.cpp
@@ -146,7 +146,7 @@ int Mixer_OSS::open()
             {
               if( devmask & ( 1 << idx ) ) // device active?
                 {
-                  Volume playbackVol( 100, 1, true, false );
+                  Volume playbackVol( 100, 0, true, false );
 		  playbackVol.addVolumeChannel(VolumeChannel(Volume::LEFT));
 		  if ( stereodevs & ( 1 << idx ) )
 		    playbackVol.addVolumeChannel(VolumeChannel(Volume::RIGHT));
@@ -163,7 +163,7 @@ int Mixer_OSS::open()
                   // Tutorial: Howto add a simple capture switch
                   if ( recmask & ( 1 << idx ) ) {
                      // can be captured => add capture volume, with no capture volume
-                     Volume captureVol( 100, 1, true, true );
+                     Volume captureVol( 100, 0, true, true );
                      md->addCaptureVolume(captureVol);
                  }
 
