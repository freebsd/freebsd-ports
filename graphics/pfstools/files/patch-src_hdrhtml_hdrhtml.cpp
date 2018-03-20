--- src/hdrhtml/hdrhtml.cpp.orig	2018-02-26 13:58:05 UTC
+++ src/hdrhtml/hdrhtml.cpp
@@ -27,6 +27,7 @@
 
 #include "hdrhtml.h"
 
+#include <limits>
 #include <algorithm>
 #include <math.h>
 #include <fstream>
@@ -197,6 +198,7 @@ public:
     this->y_i = new float[lut_size];
     own_y_i = true;
     memcpy(this->y_i, other.y_i, lut_size * sizeof(float));
+    return *this;
   }
 
   ~UniformArrayLUT()
