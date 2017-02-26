--- src/decoder/plugins/WavpackDecoderPlugin.cxx.orig	2017-01-27 07:46:51 UTC
+++ src/decoder/plugins/WavpackDecoderPlugin.cxx
@@ -34,6 +34,8 @@
 #include <stdexcept>
 #include <memory>
 
+#include <cstdlib>
+
 #include <assert.h>
 
 #define ERRORLEN 80
