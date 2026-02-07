--- lib/system.h.orig	1993-02-09 16:35:28 UTC
+++ lib/system.h
@@ -43,6 +43,7 @@ code, we suggest you use the following flags:
    _SYS_OSF	Specifics for OSF/1 for DEC Alpha (like, if it ever ships)
    _SYS_AIX	Specifics for the inferior but marketable AIX (RISC or other?)
    _SYS_HPUX	Specifics for HP-UX (8.x?) for HP 9000/700 series.
+   _SYS_BSD	Specifics for modern BSD systems (tested on FreeBSD 6.3)
    _SYS_UNIX	Basic Unix semantics, defined if any one of the above is
 
    _SYS_WATCOM  Specifics for WATCOM C/386 9.0 with apropriate libraries
@@ -86,9 +87,14 @@ following and then #including "system.h":
 #else
 #ifdef  _SYS_AUX
 #define _SYS_UNIX  /* Note: NOT _SYS_MAC */
+#else
+#ifdef  _SYS_BSD
+#define _SYS_UNIX
+#else
 #endif
 #endif
 #endif
+#endif
 #ifdef _SYS_WATCOM
 #define _SYS_DOS
 #endif
@@ -191,6 +197,9 @@ extern char *sys_errlist[]; extern int sys_nerr;
 #ifdef _SYS_ULTRIX
 #define SIGHANDLE void
 #endif
+#ifdef _SYS_BSD
+#define SIGHANDLE void
+#endif
 
 
 
@@ -210,10 +219,14 @@ seem to be real portable, so be careful.
 #ifdef _SYS_ULTRIX
 #define USE_RANDOM
 #else
+#ifdef _SYS_BSD
+#define USE_DRAND48 /* bsd has 'random' */
+#else
 #define USE_SRAND
 #endif
 #endif
 #endif
+#endif
 
 
 /***************************** C-Library **************************************
@@ -282,6 +295,14 @@ Check out their usage (arguments, etc) in syscode.c to
 #define QSORT_LENGTH       int   /* actually width is an int, not a unsigned */
 #endif
 
+#ifdef _SYS_BSD     /* modern BSD systems (tested on FreeBSD 6.3) */
+#define CALLOC_PTR_TO      char
+#define CALLOC_NUM_TYPE	   size_t /* unsigned in man page is wrong? */
+#define SIZEOF_TYPE	   size_t
+#define QSORT_DATA_PTR_TO  char
+#define QSORT_LENGTH       int   /* actually width is an int, not a unsigned */
+#endif
+
 #ifdef _SYS_AUX     /* just like ULTRIX? */
 #define CALLOC_PTR_TO      char
 #define CALLOC_NUM_TYPE	   size_t /* unsigned in man page is wrong? */
@@ -583,7 +604,7 @@ robust and portable) interfaces are provided by the li
 #include <signal.h> 
 #include <errno.h> 	
 #include <time.h>       /* for ctime() def - Who does not have this file? */
-#include <malloc.h>
+#include <stdlib.h>
 #include <sys/types.h>
 
 #ifdef TRY_WINSIZE
