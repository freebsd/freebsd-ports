--- src/hotspot/os_cpu/bsd_zero/os_bsd_zero.cpp.orig	2025-01-10 18:09:55 UTC
+++ src/hotspot/os_cpu/bsd_zero/os_bsd_zero.cpp
@@ -432,18 +432,6 @@ extern "C" {
 // Implementations of atomic operations not supported by processors.
 //  -- http://gcc.gnu.org/onlinedocs/gcc-4.2.1/gcc/Atomic-Builtins.html
 
-#ifndef _LP64
-extern "C" {
-  long long unsigned int __sync_val_compare_and_swap_8(
-    volatile void *ptr,
-    long long unsigned int oldval,
-    long long unsigned int newval) {
-    ShouldNotCallThis();
-    return 0; // silence compiler warnings
-  }
-};
-#endif // !_LP64
-
 #ifndef PRODUCT
 void os::verify_stack_alignment() {
 }
