--- src/google/protobuf/stubs/atomicops_internals_generic_gcc.h.orig	2014-08-26 03:52:37.000000000 +0800
+++ src/google/protobuf/stubs/atomicops_internals_generic_gcc.h	2015-02-21 11:38:26.948928195 +0800
@@ -83,7 +83,7 @@
 }
 
 inline void Acquire_Store(volatile Atomic32* ptr, Atomic32 value) {
-  __atomic_store_n(ptr, value, __ATOMIC_ACQUIRE);
+  __atomic_store_n(ptr, value, __ATOMIC_SEQ_CST);
 }
 
 inline void Release_Store(volatile Atomic32* ptr, Atomic32 value) {
@@ -99,7 +99,7 @@
 }
 
 inline Atomic32 Release_Load(volatile const Atomic32* ptr) {
-  return __atomic_load_n(ptr, __ATOMIC_RELEASE);
+  return __atomic_load_n(ptr, __ATOMIC_SEQ_CST);
 }
 
 #ifdef __LP64__
