--- slirp/slirp_config.h.orig	2015-11-03 20:01:35 UTC
+++ slirp/slirp_config.h
@@ -83,7 +83,7 @@
 //#undef HOST_WORDS_BIGENDIAN
 
 /* Define if you have readv */
-#undef HAVE_READV
+#define HAVE_READV
 
 /* Define if iovec needs to be declared */
 #undef DECLARE_IOVEC
@@ -92,7 +92,7 @@
 #endif
 
 /* Define if you have a POSIX.1 sys/wait.h */
-#undef HAVE_SYS_WAIT_H
+#define HAVE_SYS_WAIT_H
 
 /* Define if you have sys/select.h */
 #undef HAVE_SYS_SELECT_H
@@ -110,7 +110,7 @@
 #endif
 
 /* Define if you have sys/signal.h */
-#undef HAVE_SYS_SIGNAL_H
+#define HAVE_SYS_SIGNAL_H
 
 /* Define if you have sys/stropts.h */
 #undef HAVE_SYS_STROPTS_H
@@ -179,7 +179,7 @@
 #undef HAVE_GRANTPT
 
 /* Define if you have fchmod */
-#undef HAVE_FCHMOD
+#define HAVE_FCHMOD
 
 /* Define if you have <sys/type32.h> */
 #undef HAVE_SYS_TYPES32_H
