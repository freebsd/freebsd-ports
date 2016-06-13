--- hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp.orig	2014-03-04 02:52:15 UTC
+++ hotspot/src/os_cpu/bsd_zero/vm/os_bsd_zero.cpp
@@ -60,8 +60,8 @@
 #include "utilities/vmError.hpp"
 
 address os::current_stack_pointer() {
-  address dummy = (address) &dummy;
-  return dummy;
+  // return the address of the current function
+  return (address)__builtin_frame_address(0);
 }
 
 frame os::get_sender_for_C_frame(frame* fr) {
@@ -189,7 +189,7 @@
       ShouldNotCallThis();
     }
     else*/ if (thread->thread_state() == _thread_in_vm &&
-               sig == SIGBUS && thread->doing_unsafe_access()) {
+               (sig == SIGSEGV || sig == SIGBUS) && thread->doing_unsafe_access()) {
       ShouldNotCallThis();
     }
 
@@ -446,21 +446,6 @@ extern "C" {
   }
 };
 
-/////////////////////////////////////////////////////////////////////////////
-// Implementations of atomic operations not supported by processors.
-//  -- http://gcc.gnu.org/onlinedocs/gcc-4.2.1/gcc/Atomic-Builtins.html
-
-#ifndef _LP64
-extern "C" {
-  long long unsigned int __sync_val_compare_and_swap_8(
-    volatile void *ptr,
-    long long unsigned int oldval,
-    long long unsigned int newval) {
-    ShouldNotCallThis();
-  }
-};
-#endif // !_LP64
-
 #ifndef PRODUCT
 void os::verify_stack_alignment() {
 }
