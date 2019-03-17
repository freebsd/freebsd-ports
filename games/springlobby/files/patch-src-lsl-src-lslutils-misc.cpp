--- src/lsl/src/lslutils/misc.cpp.orig	2013-08-31 10:17:00 UTC
+++ src/lsl/src/lslutils/misc.cpp
@@ -2,7 +2,9 @@
 #include "conversion.h"
 
 #include <boost/filesystem.hpp>
+#include <boost/shared_ptr.hpp>
 #include <fstream>
+#include <cmath>
 
 namespace LSL {
 namespace Util {
