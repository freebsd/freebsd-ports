--- defs.h.orig	1993-05-31 15:17:00 UTC
+++ defs.h
@@ -43,7 +43,7 @@ typedef int		BOOLEAN;
 
 /* 'inline' patch for compilers which can't handle this */
 
-#if !( defined( __CPLUSPLUS__ ) || defined( __cplusplus ) ) || defined( __TSC__ )
+#if !( defined( __GNUC__ ) || defined( __CPLUSPLUS__ ) || defined( __cplusplus ) ) || defined( __TSC__ )
   #define inline
 #endif /* !( __CPLUSPLUS__ || __cplusplus ) */
 
