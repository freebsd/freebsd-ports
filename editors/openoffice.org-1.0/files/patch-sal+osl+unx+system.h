--- sal/osl/unx/system.h.orig	Tue Aug 20 15:54:55 2002
+++ sal/osl/unx/system.h	Thu May  8 20:31:08 2003
@@ -203,12 +203,19 @@
 #   include <dlfcn.h>
 #   include <sys/filio.h>
 #   include <sys/ioctl.h>
+#   include <sys/param.h>
 #   include <sys/time.h>
 #   include <sys/uio.h>
+#   include <sys/exec.h>
+#   include <vm/vm.h>
+#   include <vm/vm_param.h>
+#   include <vm/pmap.h>
+#   include <vm/swap_pager.h>
 #	include <sys/un.h>
 #   include <netinet/tcp.h>
 #	define 	IORESOURCE_TRANSFER_BSD 
 #   include <machine/endian.h>
+#ifdef __FreeBSD_version < 500000
 #   if BYTE_ORDER == LITTLE_ENDIAN
 #   	define _LITTLE_ENDIAN
 #   elif BYTE_ORDER == BIG_ENDIAN
@@ -216,12 +223,14 @@
 #   elif BYTE_ORDER == PDP_ENDIAN
 #   	define _PDP_ENDIAN
 #   endif
-#   define  sched_yield() 				pthread_yield()
-#   define  pthread_testcancel()
+#endif
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
@@ -569,12 +578,14 @@
 #endif
 
 #ifdef NO_PTHREAD_RTL
+#if !defined FREEBSD || (__FreeBSD_version < 500112)
 struct passwd *getpwent_r(struct passwd *pwd, char *buffer,  int buflen);
 extern struct spwd *getspnam_r(const char *name, struct spwd *result,
 							   char *buffer, int buflen);
 
 struct tm *localtime_r(const time_t *timep, struct tm *buffer);
 struct tm *gmtime_r(const time_t *timep, struct tm *buffer);
+#endif /* !defined FREEBSD || (__FreeBSD_version < 500112) */
 struct hostent *gethostbyname_r(const char *name, struct hostent *result,
 								char *buffer, int buflen, int *h_errnop);
 #endif
