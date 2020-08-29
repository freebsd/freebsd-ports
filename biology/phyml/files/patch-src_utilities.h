--- src/utilities.h.orig	2020-08-29 08:31:23 UTC
+++ src/utilities.h
@@ -94,8 +94,8 @@ static inline int isinf_ld (long double x) { return is
 #endif
 
 
-int CALL;
-int TIME;
+extern int CALL;
+extern int TIME;
 
 #define SLFV_GAUSSIAN 0 /* Spatial Lambda-Fleming-Viot model (Gaussian) */
 #define SLFV_UNIFORM 1 /* Spatial Lambda-Fleming-Viot model (Uniform) */
