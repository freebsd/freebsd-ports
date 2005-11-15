--- coregrind/vg_proxylwp.c.orig	Sat Jul 17 13:48:25 2004
+++ coregrind/vg_proxylwp.c	Mon Nov  7 20:06:46 2005
@@ -30,6 +30,7 @@
 
 
 #include "vg_include.h"
+#include "vg_unsafe.h"
 
 #ifndef UMTX_CONTESTED
 # if __FreeBSD_version < 502120
@@ -595,7 +596,7 @@
    Int ret = 1000;
    static const vki_kstack_t ss = { .ss_flags = VKI_SS_DISABLE };
 
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
    VG_(do_syscall)(__NR__umtx_lock, &px->mutex);
    px->mutex.u_owner |= UMTX_CONTESTED;
    VG_(do_syscall)(__NR_thr_self, &px->lwp);
@@ -942,7 +943,7 @@
 
    px->exitcode = ret;
 
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
    ret = VG_(do_syscall)(__NR__umtx_unlock, &px->mutex);
    if (use_rfork)
       VG_(do_syscall)(__NR_exit, 0);
@@ -1097,14 +1098,14 @@
       extern Int VG_(rfork_thread)(Int, void*, void*, void*);
       ret = VG_(rfork_thread)(VKI_RFPROC | VKI_RFMEM | VKI_RFSIGSHARE
 			      | VKI_RFTHREAD
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
 			      | VKI_RFNOWAIT
 #endif
 			      ,
 			      LWP_stack(proxy), proxylwp, proxy);
       VG_(do_signal_routing) = True;
    } else {
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
       vki_ucontext_t ctx;
       extern void makecontext(vki_ucontext_t*, ...);
 
@@ -1168,7 +1169,7 @@
       }
    }
 #endif
-#if __FreeBSD__ == 5
+#if __FreeBSD__ >= 5
    if (block) {
        if(proxy->lwp != 0)
 	   VG_(do_syscall)(__NR__umtx_lock, &proxy->mutex);
