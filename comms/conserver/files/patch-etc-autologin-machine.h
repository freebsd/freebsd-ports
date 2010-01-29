--- etc/autologin/machine.h.orig	2000-08-02 11:39:42.000000000 -0700
+++ etc/autologin/machine.h	2010-01-28 21:01:18.000000000 -0800
@@ -1,7 +1,6 @@
 /* $Id: machine.h,v 2.8 1997/11/10 17:10:34 ksb Exp $
  * leverage in liew of L7
  */
-
 #if !defined(HPUX) && (defined(HPUX7)||defined(HPUX8)||defined(HPUX9)||defined(HPUX10))
 #define HPUX	1
 #endif
@@ -17,11 +16,11 @@
 #endif
 
 #if !defined(USE_OLD_UTENT)
-#define USE_OLD_UTENT	(defined(SUN4)||defined(FREEBSD)||defined(NETBSD)||defined(S81))
+#define USE_OLD_UTENT	(defined(SUN4)||(defined(FREEBSD) && defined(__FreeBSD_version) && __FreeBSD_version < 900008)||defined(NETBSD)||defined(S81))
 #endif
 
 #if !defined(USE_UTENT)
-#define USE_UTENT	(defined(SUN5)||defined(EPIX)||defined(PARAGON)||defined(IBMR2)||defined(HPUX9)||defined(HPUX10)||defined(LINUX))
+#define USE_UTENT	(defined(SUN5)||defined(EPIX)||defined(PARAGON)||defined(IBMR2)||defined(HPUX9)||defined(HPUX10)||defined(LINUX)||(defined(__FreeBSD_version) && (__FreeBSD_version > 900007)))
 #endif
 
 #if !defined(NEED_PUTENV)
@@ -38,7 +37,7 @@
 #define USE_TERMIO	(defined(ETA10)||defined(V386))
 #endif
 #if !defined(USE_TERMIOS)
-#define USE_TERMIOS	(defined(HPUX)||defined(SUN5)||defined(PTX)||defined(IRIX5)||defined(LINUX))
+#define USE_TERMIOS	(defined(HPUX)||defined(SUN5)||defined(PTX)||defined(IRIX5)||defined(LINUX)||(defined(__FreeBSD_version) && ((__FreeBSD_version >= 800044 && __FreeBSD_version < 900000) || __FreeBSD_version > 900007)))
 #endif
 #if !defined(USE_TCBREAK)
 #define USE_TCBREAK	(defined(SUN4)||defined(PTX))
@@ -66,7 +65,7 @@
 #endif
 
 #if !defined(USE_TC)
-#define USE_TC		(defined(EPIX)||defined(IBMR2)||defined(V386)||defined(S81)||defined(PARAGON))
+#define USE_TC		(defined(EPIX)||defined(IBMR2)||defined(V386)||defined(S81)||defined(PARAGON)||(defined(__FreeBSD_version) && (__FreeBSD_version >= 800044 && __FreeBSD_version < 900000) || __FreeBSD_version > 900007))
 #endif
 
 #if !defined(HAVE_GETUSERATTR)
@@ -74,7 +73,7 @@
 #endif
 
 #if !defined(USE_IOCTL)
-#define USE_IOCTL	(defined(V386)||defined(S81)||defined(NETBSD)||defined(FREEBSD))
+#define USE_IOCTL	(defined(V386)||defined(S81)||defined(NETBSD)||(defined(FREEBSD)&&(defined(__FreeBSD_version) && (__FreeBSD_version < 800044 || (__FreeBSD_version >= 900000 &&__FreeBSD_version < 900008)))))
 #endif
 
 
@@ -127,8 +126,11 @@
 #if FREEBSD
 #include <sys/uio.h>
 #include <sys/proc.h>
+#if defined(__FreeBSD_version) && ((__FreeBSD_version >= 800044 && __FreeBSD_version < 900000) || __FreeBSD_version > 900007)
+#include <termios.h>
+#else
 #include <sys/ioctl_compat.h>
-#define setsid()	getpid()
+#endif
 #else
 
 #endif	/* NETBSD */
@@ -148,7 +150,7 @@
 #if HPUX
 #define HAVE_GETSID	(defined(HPUX10)||defined(LINUX))
 #else
-#if PARAGON || SUNOS || SUN4 || SUN5 || NETBSD || S81 || V386 || IBMR2 || EPIX
+#if PARAGON || SUNOS || SUN4 || SUN5 || NETBSD || S81 || V386 || IBMR2 || EPIX || FREEBSD
 #define HAVE_GETSID	1
 #else
 #define HAVE_GETSID	0
