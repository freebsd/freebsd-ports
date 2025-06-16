--- src/phonemize.cpp.orig	2023-11-14 17:54:34 UTC
+++ src/phonemize.cpp
@@ -3,7 +3,7 @@
 #include <vector>
 
 #include <espeak-ng/speak_lib.h>
-#include <onnxruntime_cxx_api.h>
+#include <onnxruntime/onnxruntime_cxx_api.h>
 
 #include "phonemize.hpp"
 #include "uni_algo.h"
