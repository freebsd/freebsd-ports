--- frmts/mrf/mrf_band.cpp.orig	2016-04-26 01:35:55.000000000 +0800
+++ frmts/mrf/mrf_band.cpp	2016-05-04 02:26:58.154088997 +0800
@@ -57,7 +57,7 @@
 
 #include <vector>
 #include <assert.h>
-#include "../zlib/zlib.h"
+#include <zlib.h>
 
 using std::vector;
 using std::string;
