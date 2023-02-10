--- bsd-user/host/i386/host-signal.h.orig	2022-12-14 16:28:45 UTC
+++ bsd-user/host/i386/host-signal.h
@@ -12,6 +12,7 @@
 #include <sys/param.h>
 #include <sys/ucontext.h>
 #include <machine/trap.h>
+#include <vm/vm.h>
 #include <vm/pmap.h>
 #include <machine/pmap.h>
 
