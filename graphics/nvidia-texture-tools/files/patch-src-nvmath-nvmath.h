--- src/nvmath/nvmath.h.orig	2008-12-01 11:04:28.000000000 +0300
+++ src/nvmath/nvmath.h	2009-03-06 22:38:28.000000000 +0300
@@ -97,7 +97,7 @@
 {
 #if NV_OS_WIN32
 	return _finite(f) != 0;
-#elif NV_OS_DARWIN
+#elif NV_OS_DARWIN || NV_OS_FREEBSD
 	return isfinite(f);
 #elif NV_OS_LINUX
 	return finitef(f);
@@ -112,7 +112,7 @@
 {
 #if NV_OS_WIN32
 	return _isnan(f) != 0;
-#elif NV_OS_DARWIN
+#elif NV_OS_DARWIN || NV_OS_FREEBSD
 	return isnan(f);
 #elif NV_OS_LINUX
 	return isnanf(f);
