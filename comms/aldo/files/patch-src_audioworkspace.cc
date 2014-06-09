--- src/audioworkspace.cc.orig	2007-11-05 03:58:46.000000000 -0500
+++ src/audioworkspace.cc	2014-06-08 20:17:26.477449983 -0400
@@ -31,7 +31,8 @@
 #include <cmath>
 #include <iostream>
 #include <limits>
-    
+#include <string.h>
+   
 using namespace std;
 using namespace libaudiostream;
 
@@ -104,6 +105,7 @@
 {
     ao_sample_format format;
     
+    memset(&format, 0, sizeof(format));
     format.bits = m_bits;
     format.channels = m_channels;
     format.rate = m_sample_rate;
