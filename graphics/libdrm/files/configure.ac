--- configure.ac.orig	2016-04-28 02:52:47.000000000 +0200
+++ configure.ac	2016-07-09 18:53:39.021028000 +0200
@@ -71,6 +71,11 @@
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
@@ -313,6 +318,10 @@
 	AC_DEFINE(UDEV, 1, [Have UDEV support])
 fi
 
+if test "x$DEVQ" = xyes; then
+	AC_DEFINE(DEVQ, 1, [Have DEVQ support])
+fi
+
 AC_CANONICAL_HOST
 if test "x$LIBKMS" = xauto ; then
 	case $host_os in
@@ -444,6 +453,13 @@
 fi
 AM_CONDITIONAL(HAVE_LIBUDEV, [test "x$HAVE_LIBUDEV" = xyes])
 
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
