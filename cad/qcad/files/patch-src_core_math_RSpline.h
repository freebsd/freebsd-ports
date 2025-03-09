--- src/core/math/RSpline.h.orig	2025-02-10 09:29:49 UTC
+++ src/core/math/RSpline.h
@@ -33,7 +33,7 @@ class RSplineProxy;
 class RSplineProxy;
 
 #ifndef R_NO_OPENNURBS
-#include "opennurbs/opennurbs.h"
+#include <openNURBS/opennurbs.h>
 #endif
 
 #ifndef RDEFAULT_MIN1
