--- uppsrc/Core/Defs.h.orig	2015-01-26 21:00:02 UTC
+++ uppsrc/Core/Defs.h
@@ -337,7 +337,7 @@ inline bool IsInf(double d)        { ret
 inline bool IsNaN(double d)        { return _isnan(d); }
 inline bool IsInf(double d)        { return !_finite(d) && !_isnan(d); }
 #endif
-#elif __APPLE__ || __DragonFly__
+#elif __APPLE__ || __DragonFly__ || (PLATFORM_BSD && GCC_VERSION >= 40700)
 inline bool IsNaN(double d)        { return std::isnan(d); }
 inline bool IsInf(double d)        { return std::isinf(d); }
 #else
