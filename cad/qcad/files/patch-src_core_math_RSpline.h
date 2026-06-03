--- src/core/math/RSpline.h.orig	2026-05-06 14:27:07 UTC
+++ src/core/math/RSpline.h
@@ -34,7 +34,7 @@ class RSplineProxy;
 
 #ifndef R_NO_OPENNURBS
 #if QT_VERSION >= 0x060000
-#include "opennurbs/opennurbs.h"
+#include <OpenNURBS/opennurbs.h>
 #else
 #include "legacy/opennurbs/opennurbs.h"
 #endif
