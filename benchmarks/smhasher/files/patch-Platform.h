--- Platform.h.orig	2014-04-22 21:40:50 UTC
+++ Platform.h
@@ -39,6 +39,9 @@ void SetAffinity ( int cpu );
 #else	//	defined(_MSC_VER)
 
 #include <stdint.h>
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#endif
 
 #define	FORCE_INLINE inline __attribute__((always_inline))
 #define	NEVER_INLINE __attribute__((noinline))
