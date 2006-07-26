--- xdd.h.orig	Mon Dec 19 03:13:28 2005
+++ xdd.h	Mon May 29 04:45:14 2006
@@ -46,7 +46,7 @@
 #include <sys/ipc.h>
 #include <sys/sem.h>
 #include <sys/times.h>
-#if !(SOLARIS || HPUX || AIX || OSX)
+#if !(SOLARIS || HPUX || AIX || OSX || FreeBSD)
 #include <sys/prctl.h>
 #endif
 #include <sys/param.h>
@@ -68,6 +68,11 @@
 #include <sys/procset.h>
 #include <sys/utsname.h>
 #endif
+#ifdef FreeBSD
+#include <inttypes.h>
+#include <sys/types.h>
+#include <sys/unistd.h>
+#endif
 #ifdef AIX
 #include <sys/processor.h>
 #include <ulimit.h>
@@ -90,7 +95,7 @@
 #include <sys/utsname.h>
 #endif
 /* for the global clock stuff */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 #include <netdb.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -197,7 +202,7 @@
 #ifdef HPUX
 typedef unsigned short in_port_t;
 #endif
-#if (LINUX || SOLARIS || HPUX || AIX || OSX)
+#if (LINUX || SOLARIS || HPUX || AIX || OSX || FreeBSD)
 #define MP_MUSTRUN 1 /* ASsign this thread to a specific processor */
 #define MP_NPROCS 2 /* return the number of processors on the system */
 typedef int  sd_t;  /* A socket descriptor */
@@ -290,8 +295,13 @@
 #define RX_SHARED_MEMORY    0x020000000  /* Use a shared memory segment instead of malloced memmory */
 #define RX_VERBOSE          0x040000000  /* Verbose output */
 #define RX_SEQUENCED_PATTERN 0x080000000  /* Sequenced Data Pattern in the data buffer */
+#if (FreeBSD)
+#define RX_NOMEMLOCK         0x100000000LL  /* Do not lock memory */
+#define RX_NOPROCLOCK        0x200000000LL  /* Do not lock process */
+#else
 #define RX_NOMEMLOCK         0x100000000  /* Do not lock memory */
 #define RX_NOPROCLOCK        0x200000000  /* Do not lock process */
+#endif
 /* ts_options bit settings */
 #define TS_NORMALIZE        0x00000001 /* Time stamping normalization of output*/
 #define TS_ON               0x00000002 /* Time stamping is ON */
@@ -330,14 +340,14 @@
 /* XXX *//* This needs to be converted to use a config file */
 /* Default flag values */
 #define DFL_FL_SERVER false  /* Client by default */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || FreeBSD)
 #define DFL_FL_ADDR INADDR_ANY /* Any address */  /* server only */
 #else /* Windows */
 #define DFL_FL_ADDR 0x8065b61b /* crystal 128.101.182.27 */
 #endif
 #define DFL_FL_PORT 2000  /* Port to use */
 #define DFL_FL_COUNT 10  /* Bounce a hundred times */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 #define DFL_FL_TIME 99160##000000000000LL /* Zero means don't wait */
 #else
 #define DFL_FL_TIME 99160##000000000000I64 /* Zero means don't wait */
