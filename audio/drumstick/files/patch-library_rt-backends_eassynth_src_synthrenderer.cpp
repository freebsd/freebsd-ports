--- library/rt-backends/eassynth/src/synthrenderer.cpp.orig	2016-09-24 21:08:23 UTC
+++ library/rt-backends/eassynth/src/synthrenderer.cpp
@@ -29,6 +29,7 @@
 #include <pulse/simple.h>
 #include "synthrenderer.h"
 #include "drumstickcommon.h"
+#include <assert.h>
 
 namespace drumstick {
 namespace rt {
