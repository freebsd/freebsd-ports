--- ./tools/qfcc/include/method.h.orig	Wed Feb  4 01:49:46 2004
+++ ./tools/qfcc/include/method.h	Sun Dec 17 16:07:08 2006
@@ -99,6 +99,4 @@
 
 struct expr_s *method_check_params (method_t *method, struct expr_s *args);
 
-extern struct hashtab_s *known_methods;
-
 #endif//__method_h
