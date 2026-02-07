--- src/nvmath/Matrix.cpp.orig	2020-08-24 06:27:21 UTC
+++ src/nvmath/Matrix.cpp
@@ -7,7 +7,7 @@
 
 #include <float.h>
 
-#if !NV_CC_MSVC && !NV_OS_ORBIS
+#if !NV_CC_MSVC && !NV_OS_ORBIS && !NV_OS_FREEBSD
 #include <alloca.h>
 #endif
 
