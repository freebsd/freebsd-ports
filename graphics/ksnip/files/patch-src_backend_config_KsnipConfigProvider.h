--- src/backend/config/KsnipConfigProvider.h.orig	2020-06-24 10:56:19 UTC
+++ src/backend/config/KsnipConfigProvider.h
@@ -26,7 +26,7 @@
 #include "KsnipMacConfig.h"
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "KsnipWaylandConfig.h"
 #include "src/common/platform/PlatformChecker.h"
 #endif
