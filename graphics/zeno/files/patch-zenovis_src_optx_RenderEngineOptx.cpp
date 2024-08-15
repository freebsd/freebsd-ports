--- zenovis/src/optx/RenderEngineOptx.cpp.orig	2024-04-22 12:40:25 UTC
+++ zenovis/src/optx/RenderEngineOptx.cpp
@@ -1,10 +1,10 @@
+#ifdef ZENO_ENABLE_OPTIX
 #include "optixPathTracer.h"
 #include "vec_math.h"
 #include "xinxinoptixapi.h"
 #include "zeno/utils/vec.h"
 #include <limits>
 #include <memory>
-#ifdef ZENO_ENABLE_OPTIX
 #include "../../xinxinoptix/xinxinoptixapi.h"
 #include "../../xinxinoptix/SDK/sutil/sutil.h"
 #include <zeno/types/PrimitiveObject.h>
