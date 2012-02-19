--- Opcodes/tl/fractalnoise.cpp.orig	2012-02-06 20:21:34.000000000 +0900
+++ Opcodes/tl/fractalnoise.cpp	2012-02-08 00:36:44.000000000 +0900
@@ -34,6 +34,7 @@
     return int(((unsigned int)x) >> n);
 }
 
+#if 0
 /* VECTOR INTRINSICS */
 
 inline void *aligned_calloc(size_t nmemb, size_t size)
@@ -41,6 +42,7 @@
     return (void*)((unsigned long)(calloc((nmemb*size)+15,
                                           (sizeof(char)))+15) & 0xfffffff0);
 }
+#endif
 
 /* ABSTRACT USER INTERFACE */
 
