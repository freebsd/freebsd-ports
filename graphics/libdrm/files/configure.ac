--- configure.ac.orig	2017-01-28 02:15:16.000000000 +0100
+++ configure.ac	2017-01-30 14:00:14.452530000 +0100
@@ -72,6 +72,11 @@
                               [Enable support for using udev instead of mknod (default: disabled)])],
               [UDEV=$enableval], [UDEV=no])
 
+AC_ARG_ENABLE([devq],
+              [AS_HELP_STRING([--enable-devq],
+                              [Enable support for using devq for device detection (default: disabled)])],
+              [DEVQ=$enableval], [DEVQ=no])
+
 AC_ARG_ENABLE(libkms,
 	      AS_HELP_STRING([--disable-libkms],
 	      [Disable KMS mm abstraction library (default: auto, enabled on supported platforms)]),
@@ -322,6 +327,10 @@
 	AC_DEFINE(UDEV, 1, [Have UDEV support])
 fi
 
+if test "x$DEVQ" = xyes; then
+	AC_DEFINE(DEVQ, 1, [Have DEVQ support])
+fi
+
 AC_CANONICAL_HOST
 if test "x$LIBKMS" = xauto ; then
 	case $host_os in
@@ -451,6 +460,13 @@
 AC_MSG_RESULT([$CAIRO])
 AM_CONDITIONAL(HAVE_CAIRO, [test "x$CAIRO" = xyes])
 
+# For FreeBSD support
+PKG_CHECK_MODULES([LIBDEVQ], [libdevq-1.0 >= 0.0.4], [HAVE_LIBDEVQ=yes], [HAVE_LIBDEVQ=no])
+if test "x$HAVE_LIBDEVQ" = xyes; then
+	AC_DEFINE(HAVE_LIBDEVQ, 1, [Have libdevq support])
+fi
+AM_CONDITIONAL(HAVE_LIBDEVQ, [test "x$HAVE_LIBDEVQ" = xyes])
+
 # xsltproc for docbook manpages
 AC_ARG_ENABLE([manpages],
               AS_HELP_STRING([--enable-manpages], [enable manpages @<:@default=auto@:>@]),
