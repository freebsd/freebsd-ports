--- ./src/core/math/RSpline.h.orig	2013-08-06 17:32:09.000000000 +0200
+++ ./src/core/math/RSpline.h	2013-08-08 10:33:54.000000000 +0200
@@ -30,7 +30,7 @@
 #include "RVector.h"
 
 #ifndef R_NO_OPENNURBS
-#include "opennurbs/opennurbs.h"
+#include <openNURBS/opennurbs.h>
 #endif
 
 #ifndef RDEFAULT_MIN1
