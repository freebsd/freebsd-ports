- Fix path for libpam.so on FreeBSD

Submitted by:	Landon Fuller <landonf at plausible.coop>
Sponsored by:	Plausible Labs Cooperative, Inc.
--- src/VBox/HostServices/auth/pam/VBoxAuthPAM.c.orig	2012-04-03 14:11:56.000000000 +0200
+++ src/VBox/HostServices/auth/pam/VBoxAuthPAM.c	2012-04-05 12:44:48.000000000 +0200
@@ -62,6 +62,8 @@
 /* The name of the PAM library */
 # ifdef RT_OS_SOLARIS
 #  define PAM_LIB_NAME "libpam.so.1"
+# elif defined(RT_OS_FREEBSD)
+#  define PAM_LIB_NAME "libpam.so"
 # else
 #  define PAM_LIB_NAME "libpam.so.0"
 # endif
