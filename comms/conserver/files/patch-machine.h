--- etc/conserver/machine.h.orig	Wed Aug  2 11:39:42 2000
+++ etc/conserver/machine.h	Thu Nov 23 03:45:25 2000
@@ -85,3 +85,3 @@
 #if !defined(HAVE_UWAIT)
-#define HAVE_UWAIT	!(defined(IBMR2)||defined(SUN5)||defined(HPUX8)||defined(HPUX9)||defined(HPUX10)||defined(HPUX11)||defined(PTX)||defined(IRIX5)||defined(IRIX6)||defined(LINUX))
+#define HAVE_UWAIT	!(defined(IBMR2)||defined(SUN5)||defined(HPUX8)||defined(HPUX9)||defined(HPUX10)||defined(HPUX11)||defined(PTX)||defined(IRIX5)||defined(IRIX6)||defined(LINUX)||defined(FREEBSD))
 #endif
@@ -137,3 +137,3 @@
 #if !defined(HAVE_SETSID)
-#define HAVE_SETSID	(defined(IBMR2)||defined(SUN5)||defined(HPUX)||defined(PTX)||defined(IRIX5)||defined(IRIX6)||defined(LINUX))
+#define HAVE_SETSID	(defined(IBMR2)||defined(SUN5)||defined(HPUX)||defined(PTX)||defined(IRIX5)||defined(IRIX6)||defined(LINUX)||defined(FREEBSD))
 #endif
@@ -159,3 +159,3 @@
 #if !defined(USE_TERMIOS)
-#define USE_TERMIOS	(defined(HPUX)||defined(SUN5)||defined(PTX)||defined(IRIX5)||defined(IRIX6)||defined(LINUX))
+#define USE_TERMIOS	(defined(HPUX)||defined(SUN5)||defined(PTX)||defined(IRIX5)||defined(IRIX6)||defined(LINUX)||defined(FREEBSD))
 #endif
