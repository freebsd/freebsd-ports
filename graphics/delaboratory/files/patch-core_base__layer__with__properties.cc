--- core/base_layer_with_properties.cc.orig	2012-07-10 23:38:22 UTC
+++ core/base_layer_with_properties.cc
@@ -19,7 +19,7 @@
 #include "base_layer_with_properties.h"
 #include "color_space_utils.h"
 #include "logger.h"
-#include "semaphore.h"
+#include "desemaphore.h"
 #include "str.h"
 #include "property_numeric.h"
 #include "property_boolean.h"
