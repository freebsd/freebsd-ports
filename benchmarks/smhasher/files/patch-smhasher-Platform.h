--- Platform.h	2015-03-30 17:28:57.000000000 -0400
+++ Platform.h.new	2015-03-30 17:28:51.000000000 -0400
@@ -39,6 +39,9 @@
 #else	//	defined(_MSC_VER)
 
 #include <stdint.h>
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#endif
 
 #define	FORCE_INLINE inline __attribute__((always_inline))
 #define	NEVER_INLINE __attribute__((noinline))
