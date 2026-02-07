--- ccast/axTLS/os_int.h.orig	2016-09-28 03:00:00 UTC
+++ ccast/axTLS/os_int.h
@@ -34,6 +34,7 @@ extern "C" {
 #if (__STDC_VERSION__ >= 199901L)	/* C99 */		\
  || defined(_STDINT_H_) || defined(_STDINT_H)		\
  || defined(_SYS_TYPES_H)							\
+ || defined(__powerpc64__) || defined(POWERPC64)	\
  || (defined(__APPLE__) && defined(__POWERPC__))
 
 #include <stdint.h> 
