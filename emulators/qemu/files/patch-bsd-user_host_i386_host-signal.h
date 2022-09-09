--- bsd-user/host/i386/host-signal.h.orig	2022-09-08 16:00:45 UTC
+++ bsd-user/host/i386/host-signal.h
@@ -9,6 +9,9 @@
 #ifndef I386_HOST_SIGNAL_H
 #define I386_HOST_SIGNAL_H
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/param.h>
+#endif
 #include <sys/ucontext.h>
 #include <machine/trap.h>
 #include <vm/pmap.h>
