--- frmts/mrf/mrf_band.cpp.orig	2016-04-25 17:35:55 UTC
+++ frmts/mrf/mrf_band.cpp
@@ -57,7 +57,7 @@
 
 #include <vector>
 #include <assert.h>
-#include "../zlib/zlib.h"
+#include <zlib.h>
 
 using std::vector;
 using std::string;
