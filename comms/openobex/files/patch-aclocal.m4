--- aclocal.m4.orig	Wed Jun 14 15:58:25 2006
+++ aclocal.m4	Sat Nov 25 21:55:24 2006
@@ -6914,6 +6914,37 @@
 # AM_CONFIG_HEADER is obsolete.  It has been replaced by AC_CONFIG_HEADERS.
 AU_DEFUN([AM_CONFIG_HEADER], [AC_CONFIG_HEADERS($@)])
 
+
+dnl adding a check for FreeBSD blutooth netgraph support.
+
+AC_DEFUN([FREEBSD_BLUETOOTH_HOOK],[
+	AC_MSG_CHECKING([for the FreeBSD/netgraph bluetooth support])
+	echo
+	AC_CHECK_LIB(bluetooth, bt_aton,
+	[AC_CACHE_CHECK(for the struct sockaddr_rfcomm in <netgraph/.../ng_btsocket.h>, ac_cv_have_sockaddr_rfcomm,
+	[AC_TRY_COMPILE([#include <sys/types.h>
+			#include <sys/socket.h>
+			#include <bitstring.h>
+			#include <netgraph/bluetooth/include/ng_hci.h>
+			#include <netgraph/bluetooth/include/ng_l2cap.h>
+			#include <netgraph/bluetooth/include/ng_btsocket.h>],
+		[struct sockaddr_rfcomm rc;],
+		ac_cv_have_sockaddr_rfcomm=yes,
+		ac_cv_have_sockaddr_rfcomm=no)])
+
+	if test $ac_cv_have_sockaddr_rfcomm = yes; then
+		AC_DEFINE(HAVE_BLUETOOTH)
+		AC_DEFINE(HAVE_BLUETOOTH_NETGRAPH,1,[Compile on FreeBSD])
+		USE_BLUETOOTH="yes"
+		LIBS="$LIBS -lbluetooth"
+		AC_DEFINE(HAVE_BT_ATON,1,[Define to 1 if you have the \`bt_aton' function.])
+	fi
+])])
+
+AC_DEFUN([FREEBSD_BLUETOOTH_CHECK], [
+	FREEBSD_BLUETOOTH_HOOK([],failure)
+])
+
 # Do all the work for Automake.                             -*- Autoconf -*-
 
 # Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005
