commit c76381656baeee9bdeddd899cb595c2b45294597
Author: Dimitry Andric <dim@FreeBSD.org>
Date:   2023-05-29 19:50:57 +0200

    lang/sbcl: fix build with clang 16
    
    Clang 16 has a new error about incompatible function types, which shows
    up when building lang/sbcl:
    
      bsd-os.c:285:50: error: incompatible function pointer types passing '__siginfohandler_t *' (aka 'void (*)(int, struct __siginfo *, void *)') to parameter of type 'interrupt_handler_t' (aka 'void (*)(int, struct __siginfo *, struct __ucontext *)') [-Wincompatible-function-pointer-types]
                                                       (__siginfohandler_t *)
                                                       ^~~~~~~~~~~~~~~~~~~~~~
      ./interrupt.h:123:64: note: passing argument to parameter 'handler' here
      extern void ll_install_handler(int signal, interrupt_handler_t handler);
                                                                     ^
    
    Indeed the __siginfohandler_t type is incompatible, but that is caused
    by the cast itself, which does not seem to be good for anything. Remove
    it, so the mismatch is gone.

diff --git a/lang/sbcl/files/patch-src_runtime_bsd-os.c b/lang/sbcl/files/patch-src_runtime_bsd-os.c
new file mode 100644
index 000000000000..3faf2f345709
--- /dev/null
+++ b/lang/sbcl/files/patch-src_runtime_bsd-os.c
@@ -0,0 +1,15 @@
+--- src/runtime/bsd-os.c.orig	2023-04-30 08:33:10 UTC
++++ src/runtime/bsd-os.c
+@@ -280,11 +280,7 @@ os_install_interrupt_handlers(void)
+ os_install_interrupt_handlers(void)
+ {
+     if (INSTALL_SIG_MEMORY_FAULT_HANDLER) {
+-    ll_install_handler(SIG_MEMORY_FAULT,
+-#if defined(LISP_FEATURE_FREEBSD) && !defined(__GLIBC__)
+-                                                 (__siginfohandler_t *)
+-#endif
+-                                                 memory_fault_handler);
++    ll_install_handler(SIG_MEMORY_FAULT, memory_fault_handler);
+ 
+ #ifdef LISP_FEATURE_DARWIN
+     /* Unmapped pages get this and not SIGBUS. */

