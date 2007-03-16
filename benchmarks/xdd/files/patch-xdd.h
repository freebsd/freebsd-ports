--- xdd.h.orig	Fri Mar 16 06:35:11 2007
+++ xdd.h	Fri Mar 16 07:04:35 2007
@@ -48,7 +48,7 @@
 #include <sys/ipc.h>
 #include <sys/sem.h>
 #include <sys/times.h>
-#if !(SOLARIS || HPUX || AIX || OSX)
+#if !(SOLARIS || HPUX || AIX || OSX || FreeBSD)
 #include <sys/prctl.h>
 #endif
 #include <sys/param.h>
@@ -70,6 +70,11 @@
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
@@ -92,7 +97,7 @@
 #include <sys/utsname.h>
 #endif
 /* for the global clock stuff */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 #include <netdb.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -199,7 +204,7 @@
 #ifdef HPUX
 typedef unsigned short in_port_t;
 #endif
-#if (LINUX || SOLARIS || HPUX || AIX || OSX)
+#if (LINUX || SOLARIS || HPUX || AIX || OSX || FreeBSD)
 #define MP_MUSTRUN 1 /* ASsign this thread to a specific processor */
 #define MP_NPROCS 2 /* return the number of processors on the system */
 typedef int  sd_t;  /* A socket descriptor */
@@ -291,6 +296,18 @@
 #define RX_SHARED_MEMORY      (uint64_t) 0x0000000020000000  /* Use a shared memory segment instead of malloced memmory */
 #define RX_VERBOSE            (uint64_t) 0x0000000040000000  /* Verbose output */
 #define RX_SEQUENCED_PATTERN  (uint64_t) 0x0000000080000000  /* Sequenced Data Pattern in the data buffer */
+#if (FreeBSD)
+#define RX_ASCII_PATTERN      (uint64_t) 0x0000000100000000LL  /* ASCII Data Pattern in the data buffer */
+#define RX_HEX_PATTERN        (uint64_t) 0x0000000200000000LL  /* HEXIDECIMAL Data Pattern in the data buffer */
+#define RX_SINGLECHAR_PATTERN (uint64_t) 0x0000000400000000LL  /* HEXIDECIMAL Data Pattern in the data buffer */
+#define RX_FILE_PATTERN       (uint64_t) 0x0000000800000000LL  /* Name of file that contains the Data Pattern */
+#define RX_REPLICATE_PATTERN  (uint64_t) 0x0000001000000000LL  /* Replicate Data Pattern throughout the data buffer */
+#define RX_NOMEMLOCK          (uint64_t) 0x0000002000000000LL  /* Do not lock memory */
+#define RX_NOPROCLOCK         (uint64_t) 0x0000004000000000LL  /* Do not lock process */
+#define RX_REOPEN             (uint64_t) 0x0000008000000000LL  /* Open/Close target on each pass and record time */
+#define RX_CREATE_NEW_FILES   (uint64_t) 0x0000010000000000LL  /* Create new targets for each pass */
+#define RX_RECREATE           (uint64_t) 0x0000020000000000LL  /* ReCreate targets for each pass */
+#else
 #define RX_ASCII_PATTERN      (uint64_t) 0x0000000100000000  /* ASCII Data Pattern in the data buffer */
 #define RX_HEX_PATTERN        (uint64_t) 0x0000000200000000  /* HEXIDECIMAL Data Pattern in the data buffer */
 #define RX_SINGLECHAR_PATTERN (uint64_t) 0x0000000400000000  /* HEXIDECIMAL Data Pattern in the data buffer */
@@ -301,6 +318,7 @@
 #define RX_REOPEN             (uint64_t) 0x0000008000000000  /* Open/Close target on each pass and record time */
 #define RX_CREATE_NEW_FILES   (uint64_t) 0x0000010000000000  /* Create new targets for each pass */
 #define RX_RECREATE           (uint64_t) 0x0000020000000000  /* ReCreate targets for each pass */
+#endif /* (FreeBSD) */
 
 /* ts_options bit settings */
 #define TS_NORMALIZE          0x00000001 /* Time stamping normalization of output*/
@@ -340,14 +358,14 @@
 /* XXX *//* This needs to be converted to use a config file */
 /* Default flag values */
 #define DFL_FL_SERVER false  /* Client by default */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || FreeBSD)
 #define DFL_FL_ADDR INADDR_ANY /* Any address */  /* server only */
 #else /* Windows */
 #define DFL_FL_ADDR 0x8065b61b /*  128.101.182.27 */
 #endif
 #define DFL_FL_PORT 2000  /* Port to use */
 #define DFL_FL_COUNT 10  /* Bounce a hundred times */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 #define DFL_FL_TIME 99160##000000000000LL /* Zero means don't wait */
 #else
 #define DFL_FL_TIME 99160##000000000000I64 /* Zero means don't wait */
