--- ./ccast/axTLS/os_int.h.orig
+++ ./ccast/axTLS/os_int.h
@@ -34,6 +34,7 @@
 #if (__STDC_VERSION__ >= 199901L)	/* C99 */		\
  || defined(_STDINT_H_) || defined(_STDINT_H)		\
  || defined(_SYS_TYPES_H)							\
+ || defined(__powerpc64__) || defined(POWERPC64)	\
  || (defined(__APPLE__) && defined(__POWERPC__))
 
 #include <stdint.h> 

