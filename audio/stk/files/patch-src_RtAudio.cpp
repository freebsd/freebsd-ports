--- src/RtAudio.cpp.orig	2016-02-23 01:51:06 UTC
+++ src/RtAudio.cpp
@@ -47,6 +47,11 @@
 #include <climits>
 #include <algorithm>
 
+#if defined(__FreeBSD__)
+#include <sys/soundcard.h>
+#define AFMT_FLOAT 0x00004000
+#endif
+
 // Static variable definitions.
 const unsigned int RtApi::MAX_SAMPLE_RATES = 14;
 const unsigned int RtApi::SAMPLE_RATES[] = {
@@ -9023,7 +9028,7 @@ bool RtApiOss :: probeDeviceOpen( unsign
   }
 
   // Verify the sample rate setup worked.
-  if ( abs( srate - sampleRate ) > 100 ) {
+  if ( abs( (int)(srate - sampleRate) ) > 100 ) {
     close( fd );
     errorStream_ << "RtApiOss::probeDeviceOpen: device (" << ainfo.name << ") does not support sample rate (" << sampleRate << ").";
     errorText_ = errorStream_.str();
