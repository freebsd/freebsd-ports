--- src/GlideHQ/TxCache.cpp	2024-09-09 20:35:22.594270000 -0700
+++ src/GlideHQ/TxCache.cpp	2024-09-09 20:35:30.949063000 -0700
@@ -25,6 +25,7 @@
 #pragma warning(disable: 4786)
 #endif
 
+#include <unistd.h>
 #include <filesystem>
 #include <zlib.h>
 #include "TxCache.h"
