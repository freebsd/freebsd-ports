--- ../sal/osl/unx/system.h.orig	Wed Jun  5 16:24:19 2002
+++ ../sal/osl/unx/system.h	Sun Jan 12 15:48:03 2003
@@ -205,6 +205,13 @@
 #   include <sys/ioctl.h>
 #   include <sys/time.h>
 #   include <sys/uio.h>
+#   include <sys/exec.h>
+#   include <vm/vm.h>
+#   include <vm/vm_param.h>
+#   include <vm/pmap.h>
+#   include <vm/swap_pager.h>
+#   include <machine/vmparam.h>
+#   include <machine/pmap.h>
 #	include <sys/un.h>
 #   include <netinet/tcp.h>
 #	define 	IORESOURCE_TRANSFER_BSD 
@@ -216,12 +223,13 @@
 #   elif BYTE_ORDER == PDP_ENDIAN
 #   	define _PDP_ENDIAN
 #   endif
-#   define  sched_yield() 				pthread_yield()
-#   define  pthread_testcancel()
 #	define  NO_PTHREAD_RTL
-#	define  NO_PTHREAD_PRIORITY
-#	define  CMD_ARG_PRG					__progname		
-#	define  CMD_ARG_ENV					environ
+/* __progname isn't sufficient here. We need the full path as well 
+ * for e.g. setup and __progname only points to the binary name. 
+ */
+#	define  CMD_ARG_PRG_IS_DEFINED
+#	define  CMD_ARG_PRG			*((struct ps_strings *)PS_STRINGS)->ps_argvstr
+#	define  CMD_ARG_ENV			environ
 #endif
 
 #ifdef SCO
