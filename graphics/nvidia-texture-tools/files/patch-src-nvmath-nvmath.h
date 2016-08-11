--- src/nvmath/nvmath.h.orig	2010-05-15 09:12:05 UTC
+++ src/nvmath/nvmath.h
@@ -115,7 +115,7 @@ inline bool isFinite(const float f)
 {
 #if NV_OS_WIN32
 	return _finite(f) != 0;
-#elif NV_OS_DARWIN
+#elif NV_OS_DARWIN || NV_OS_FREEBSD
 	return isfinite(f);
 #elif NV_OS_LINUX
 	return finitef(f);
@@ -130,7 +130,7 @@ inline bool isNan(const float f)
 {
 #if NV_OS_WIN32
 	return _isnan(f) != 0;
-#elif NV_OS_DARWIN
+#elif NV_OS_DARWIN || NV_OS_FREEBSD
 	return isnan(f);
 #elif NV_OS_LINUX
 	return isnanf(f);
