--- code/globalincs/pstypes.h.orig	2023-11-24 00:40:45 UTC
+++ code/globalincs/pstypes.h
@@ -18,7 +18,7 @@
 #include <memory.h>
 #include <string.h>
 
-#if defined( __x86_64__ ) || defined( _WIN64 )
+#if defined( __LP64__ ) || defined( _WIN64 )
 #define IAM_64BIT 1
 #endif
 
