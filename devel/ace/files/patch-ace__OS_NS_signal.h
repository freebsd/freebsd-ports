--- ace/OS_NS_signal.h.orig	2011-03-04 23:59:09.000000000 +0900
+++ ace/OS_NS_signal.h	2011-11-27 07:50:01.000000000 +0900
@@ -33,10 +33,10 @@
 #endif
 #define ACE_EXPORT_MACRO ACE_Export
 
-#if defined (__Lynx__) || defined (__OpenBSD__)
-// LynxOS and OpenBSD define pthread_sigmask() in pthread.h
+#if defined (__Lynx__) || defined (__OpenBSD__) || defined (__FreeBSD__)
+// LynxOS, OpenBSD and FreeBSD define pthread_sigmask() in pthread.h
 # include "ace/os_include/os_pthread.h"
-#endif /* __Lynx__ || OpenBSD */
+#endif /* __Lynx__ || OpenBSD || FreeBSD */
 
 /*
  * We inline and undef some functions that may be implemented
