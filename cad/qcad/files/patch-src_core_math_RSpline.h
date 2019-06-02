--- src/core/math/RSpline.h.orig	2019-05-01 14:25:33 UTC
+++ src/core/math/RSpline.h
@@ -32,7 +32,7 @@
 #include "RPolyline.h"
 
 #ifndef R_NO_OPENNURBS
-#include "opennurbs/opennurbs.h"
+#include <openNURBS/opennurbs.h>
 #endif
 
 #ifndef RDEFAULT_MIN1
