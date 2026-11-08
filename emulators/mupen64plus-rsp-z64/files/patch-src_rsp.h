--- src/rsp.h.orig	2024-05-27 02:51:19 UTC
+++ src/rsp.h
@@ -380,7 +380,9 @@ INLINE void n64_dp_reg_w(UINT32 offset, UINT32 data, U
     }
 }
 
+#if defined(__i386__) || defined(__x86_64__) || defined(_M_IX86) || defined(_M_X64)
 #define INTEL86
+#endif
 #if defined(INTEL86) && defined __GNUC__ && __GNUC__ >= 2
 static __inline__ unsigned long long RDTSC(void)
 {
