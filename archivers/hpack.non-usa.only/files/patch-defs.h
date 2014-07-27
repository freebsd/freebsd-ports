--- defs.h.orig	Mon May 31 10:17:00 1993
+++ defs.h	Tue Dec 28 20:01:38 1999
@@ -43,7 +43,7 @@
 
 /* 'inline' patch for compilers which can't handle this */
 
-#if !( defined( __CPLUSPLUS__ ) || defined( __cplusplus ) ) || defined( __TSC__ )
+#if !( defined( __GNUC__ ) || defined( __CPLUSPLUS__ ) || defined( __cplusplus ) ) || defined( __TSC__ )
   #define inline
 #endif /* !( __CPLUSPLUS__ || __cplusplus ) */
 
