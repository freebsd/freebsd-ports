--- src/audioworkspace.cc.orig	2007-11-05 08:58:46 UTC
+++ src/audioworkspace.cc
@@ -31,7 +31,8 @@
 #include <cmath>
 #include <iostream>
 #include <limits>
-    
+#include <string.h>
+   
 using namespace std;
 using namespace libaudiostream;
 
@@ -104,6 +105,7 @@ oastream AudioWorkSpace::create_output_s
 {
     ao_sample_format format;
     
+    memset(&format, 0, sizeof(format));
     format.bits = m_bits;
     format.channels = m_channels;
     format.rate = m_sample_rate;
