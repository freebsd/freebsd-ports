--- libs/basekit/source/Common_inline.h.orig	2011-09-13 00:14:12.000000000 +0200
+++ libs/basekit/source/Common_inline.h	2012-10-02 16:18:38.000000000 +0200
@@ -52,7 +52,9 @@
 
 #if defined(__APPLE__) 
 
-	#define NS_INLINE static __inline__ __attribute__((always_inline))
+	#ifndef NS_INLINE
+		#define NS_INLINE static __inline__ __attribute__((always_inline))
+	#endif
 
 	#ifdef IO_IN_C_FILE
 		// in .c 
@@ -108,7 +110,7 @@
 		#define IOINLINE static inline
 	#endif 
 	
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__)
 
 	#ifdef IO_IN_C_FILE
 		// in .c 
