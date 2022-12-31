--- bsd-user/host/i386/host-signal.h.orig	2022-12-14 16:28:45 UTC
+++ bsd-user/host/i386/host-signal.h
@@ -13,6 +13,7 @@
 #include <sys/ucontext.h>
 #include <machine/trap.h>
 #include <vm/pmap.h>
+#include <vm/vm.h>
 #include <machine/pmap.h>
 
 static inline uintptr_t host_signal_pc(ucontext_t *uc)
