Fix build with boost 1.85.

--- src/Libpfs/manip/resize.hxx.orig	2024-05-30 18:37:03.836910306 +0000
+++ src/Libpfs/manip/resize.hxx
@@ -23,6 +23,7 @@
 #define PFS_RESIZE_HXX
 
 #include <boost/math/constants/constants.hpp>
+#include <boost/numeric/conversion/bounds.hpp>
 #include "copy.h"
 #include "resize.h"
 #include "../../sleef.c"
