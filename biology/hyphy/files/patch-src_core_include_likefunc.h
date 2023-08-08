--- src/core/include/likefunc.h.orig	2023-06-27 12:50:39 UTC
+++ src/core/include/likefunc.h
@@ -282,9 +282,6 @@ class   _LikelihoodFunction: public BaseObj { (public)
     long        GetThreadCount            (void) {
         return 1L;
     }
-    void        SetThreadCount            (long) {
-        
-    }
 #endif
 #endif
 
