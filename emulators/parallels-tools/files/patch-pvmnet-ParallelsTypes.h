--- pvmnet/ParallelsTypes.h	2021-05-31 02:45:16 UTC
+++ pvmnet/ParallelsTypes.h	
@@ -48,6 +48,8 @@ 
 #ifndef _32BIT_
 	#define _32BIT_
 #endif
+#elif defined(__aarch64__)
+	#define _64BIT_
 #else
 	#error "Failed to determine processor architecture"
 #endif
