--- gio/tests/gdbus-peer.c.orig	2010-08-16 21:30:03.000000000 +0200
+++ gio/tests/gdbus-peer.c	2010-08-16 23:13:32.000000000 +0200
@@ -42,6 +42,8 @@
 #include <sys/socket.h>
 #endif
 
+#include <sys/socket.h>
+
 /* used in test_overflow */
 #ifdef G_OS_UNIX
 #include <gio/gunixconnection.h>
