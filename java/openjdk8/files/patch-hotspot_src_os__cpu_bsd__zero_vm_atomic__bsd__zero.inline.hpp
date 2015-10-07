--- hotspot/src/os_cpu/bsd_zero/vm/atomic_bsd_zero.inline.hpp.orig	2015-06-03 16:41:00 UTC
+++ hotspot/src/os_cpu/bsd_zero/vm/atomic_bsd_zero.inline.hpp
@@ -112,8 +112,16 @@ static inline int m68k_lock_test_and_set
  *
  */
 
+#if defined(__FreeBSD__)
+#include <machine/atomic.h>
+#define __kernel_cmpxchg(oldval, newval, ptr) (!atomic_cmpset_rel_32((volatile u_int32_t *)(ptr), (u_int32_t)(oldval), (u_int32_t)(newval)))
+#elif defined(__NetBSD__)
+#include <sys/atomic.h>
+#define __kernel_cmpxchg(oldval, newval, ptr) ((unsigned int)(oldval) != atomic_cas_uint((volatile unsigned int*)(ptr), (unsigned int)(oldval), (unsigned int)(newval)))
+#else
 typedef int (__kernel_cmpxchg_t)(int oldval, int newval, volatile int *ptr);
 #define __kernel_cmpxchg (*(__kernel_cmpxchg_t *) 0xffff0fc0)
+#endif
 
 
 
@@ -177,7 +185,7 @@ inline void Atomic::store_ptr(intptr_t s
 
 inline jint Atomic::add(jint add_value, volatile jint* dest) {
 #ifdef ARM
-  return arm_add_and_fetch(dest, add_value);
+  return arm_add_and_fetch((volatile int*)dest, add_value);
 #else
 #ifdef M68K
   return m68k_add_and_fetch(dest, add_value);
@@ -189,7 +197,7 @@ inline jint Atomic::add(jint add_value, 
 
 inline intptr_t Atomic::add_ptr(intptr_t add_value, volatile intptr_t* dest) {
 #ifdef ARM
-  return arm_add_and_fetch(dest, add_value);
+  return arm_add_and_fetch((volatile int*)dest, add_value);
 #else
 #ifdef M68K
   return m68k_add_and_fetch(dest, add_value);
@@ -286,7 +294,7 @@ inline intptr_t Atomic::cmpxchg_ptr(intp
                                     volatile intptr_t* dest,
                                     intptr_t compare_value) {
 #ifdef ARM
-  return arm_compare_and_swap(dest, compare_value, exchange_value);
+  return arm_compare_and_swap((volatile int*)dest, compare_value, exchange_value);
 #else
 #ifdef M68K
   return m68k_compare_and_swap(dest, compare_value, exchange_value);
