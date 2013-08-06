--- client/vector/analyzeFuncs_x86_64.cpp.orig	2011-04-03 07:25:53.000000000 +0200
+++ client/vector/analyzeFuncs_x86_64.cpp	2013-07-29 17:41:37.000000000 +0200
@@ -61,8 +61,14 @@
     static const int as [4]  __attribute__((aligned(16)))= {INT_MIN, 0, INT_MIN, 0} ; // {-, +, -, +}
     char *cblock = (char *)alloca(11*16);
     cblock+=(16-((ssize_t)cblock % 16));
+#ifdef __clang__
+    __m128 *fblock=reinterpret_cast<__m128 *>(cblock);
+    __m128d *dblock=reinterpret_cast<__m128d *>(cblock);
+#else
     x86_m128 *fblock=reinterpret_cast<x86_m128 *>(cblock);
     x86_m128d *dblock=reinterpret_cast<x86_m128d *>(cblock);
+#endif
+    
     #define CC dblock[0]
     #define DD dblock[1]
     #define cc fblock[2]
