--- mysqlshdk/libs/utils/uuid_gen.cc.orig	2026-01-26 17:13:17 UTC
+++ mysqlshdk/libs/utils/uuid_gen.cc
@@ -36,7 +36,7 @@
 #include <windows.h>
 #include <algorithm>
 // clang-format on
-#elif __APPLE__
+#else
 #include <pthread.h>
 #endif
 
