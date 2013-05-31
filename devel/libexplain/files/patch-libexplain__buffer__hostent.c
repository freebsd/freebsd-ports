--- ./libexplain/buffer/hostent.c.orig	2013-03-15 02:34:07.000000000 +0100
+++ ./libexplain/buffer/hostent.c	2013-05-31 10:52:55.842570569 +0200
@@ -28,6 +28,10 @@
 #include <libexplain/buffer/sockaddr.h>
 #include <libexplain/is_efault.h>
 
+#ifdef  __FreeBSD__
+#include <sys/socket.h>
+#endif
+
 
 void
 explain_buffer_hostent(explain_string_buffer_t *sb,
