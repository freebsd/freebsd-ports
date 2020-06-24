--- src/backend/config/KsnipConfigProvider.cpp.orig	2020-06-24 10:56:34 UTC
+++ src/backend/config/KsnipConfigProvider.cpp
@@ -26,7 +26,7 @@ KsnipConfig* KsnipConfigProvider::instance()
 	return &instance;
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	if (PlatformChecker::instance()->isWayland()) {
 		static KsnipWaylandConfig instance;
 		return &instance;
