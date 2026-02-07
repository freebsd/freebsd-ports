--- ficlplatform/unix.h.orig	2010-09-15 18:29:10 UTC
+++ ficlplatform/unix.h
@@ -13,7 +13,7 @@
 #else
 #define FICL_PLATFORM_ALIGNMENT       (4)
 #endif
-#define FICL_PLATFORM_INLINE          inline
+#define FICL_PLATFORM_INLINE          static inline
 
 #define FICL_PLATFORM_HAS_FTRUNCATE   (1)
 #if defined(__amd64__)
