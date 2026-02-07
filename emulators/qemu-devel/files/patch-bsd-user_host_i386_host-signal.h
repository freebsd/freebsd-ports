--- bsd-user/host/i386/host-signal.h.orig	2023-05-05 21:12:05 UTC
+++ bsd-user/host/i386/host-signal.h
@@ -12,6 +12,7 @@
 #include <sys/param.h>
 #include <sys/ucontext.h>
 #include <machine/trap.h>
+#include <vm/vm.h>
 #include <vm/pmap.h>
 #include <machine/pmap.h>
 
