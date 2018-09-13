--- projects/openmp/libomptarget/src/omptarget.cpp.orig
+++ projects/openmp/libomptarget/src/omptarget.cpp
@@ -12,6 +12,7 @@
 //
 //===----------------------------------------------------------------------===//
 
+#include <stdarg.h>
 #include <omptarget.h>
 
 #include "device.h"
