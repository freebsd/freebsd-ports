--- src/output/RtAudio/rtaudio/RtAudio.cpp.intermediate	2014-04-04 08:59:58.181014000 +0000
+++ src/output/RtAudio/rtaudio/RtAudio.cpp
@@ -57,6 +57,7 @@
 #include "RtAudio.h"
 #include <iostream>
 #include <stdio.h>
+#include <string.h>
 
 // Static variable definitions.
 const unsigned int RtApi::MAX_SAMPLE_RATES = 14;
