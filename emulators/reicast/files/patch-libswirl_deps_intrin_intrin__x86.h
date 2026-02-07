--- libswirl/deps/intrin/intrin_x86.h.orig	2018-11-26 23:44:32 UTC
+++ libswirl/deps/intrin/intrin_x86.h
@@ -896,9 +896,11 @@ static __inline__ __attribute__((always_inline)) unsig
 #endif  // !HAS_BUILTIN(__rdtsc)
 
 /*** Interrupts ***/
+/*
 static __inline__ __attribute__((always_inline)) void __debugbreak(void) {
   __asm__("int $3");
 }
+*/
 
 static __inline__ __attribute__((always_inline)) void __int2c(void) {
   __asm__("int $0x2c");
