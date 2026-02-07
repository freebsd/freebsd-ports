--- src/GlideHQ/TxHiResCache.cpp	2024-09-09 20:36:34.576202000 -0700
+++ src/GlideHQ/TxHiResCache.cpp	2024-09-09 20:36:53.620099000 -0700
@@ -52,6 +52,7 @@
  * (0:disable, 1:enable, 2:extreme) */
 #define AGGRESSIVE_QUANTIZATION 1
 
+#include <unistd.h>
 #include <zlib.h>
 #include <string>
 #include <SDL.h>
