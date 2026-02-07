--- src/compiler.h.orig	2024-01-31 20:08:46 UTC
+++ src/compiler.h
@@ -74,7 +74,9 @@
 
 #define __ALIGN_MASK(x, mask)   (((x) + (mask)) & ~(mask))
 #define __ALIGN(x, a)           __ALIGN_MASK(x, (typeof(x))(a) - 1)
-#define ALIGN(x, a)             __ALIGN((x), (a))
+#if !defined(ALIGN)
+# define ALIGN(x, a)             __ALIGN((x), (a))
+#endif
 #define ALIGN_DOWN(x, a)        __ALIGN((x) - ((a) - 1), (a))
 
 #define ALIGNMENT_PADDING(value, align) ((align - (value % align)) % align)
