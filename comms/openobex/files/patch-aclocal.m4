--- aclocal.m4.orig	Wed Jun 16 19:59:04 2004
+++ aclocal.m4	Wed Jun 16 20:26:17 2004
@@ -67,6 +67,36 @@
 	BLUETOOTH_HOOK([],failure)
 ])
 
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
 # Do all the work for Automake.  This macro actually does too much --
 # some checks are only needed if your package does certain things.
 # But this isn't really a big deal.
