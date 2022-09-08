--- bsd-user/host/x86_64/host-signal.h.orig	2022-04-19 19:10:27 UTC
+++ bsd-user/host/x86_64/host-signal.h
@@ -9,6 +9,9 @@
 #ifndef X86_64_HOST_SIGNAL_H
 #define X86_64_HOST_SIGNAL_H
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 #include <sys/ucontext.h>
 #include <machine/trap.h>
 #include <vm/pmap.h>
