--- ../sal/osl/unx/system.h.orig	Mon Mar 11 01:41:13 2002
+++ ../sal/osl/unx/system.h	Mon Mar 11 01:41:25 2002
@@ -216,10 +216,7 @@
 #   elif BYTE_ORDER == PDP_ENDIAN
 #   	define _PDP_ENDIAN
 #   endif
-#   define  sched_yield() 				pthread_yield()
-#   define  pthread_testcancel()
 #	define  NO_PTHREAD_RTL
-#	define  NO_PTHREAD_PRIORITY
 #	define  CMD_ARG_PRG					__progname		
 #	define  CMD_ARG_ENV					environ
 #endif
