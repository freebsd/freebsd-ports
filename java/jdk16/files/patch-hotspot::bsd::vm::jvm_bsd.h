--- ../../hotspot/src/os/bsd/vm/jvm_bsd.h.orig	Fri May 25 14:04:51 2007
+++ ../../hotspot/src/os/bsd/vm/jvm_bsd.h	Fri May 25 14:04:14 2007
@@ -78,8 +78,12 @@
 #define ALT_ASYNC_SIGNAL     ALT_INTERRUPT_SIGNAL+1  /* alternate async signal */
 
 /* XXXBSD: compat? */
+#ifndef SIGRTMIN
 #define SIGRTMIN	33
+#endif
+#ifndef SIGRTMAX
 #define SIGRTMAX	63
+#endif
 
 /* With 1.4.1 libjsig added versioning: used in os_bsd.cpp and jsig.c */
 #define JSIG_VERSION_1_4_1   0x30140100
