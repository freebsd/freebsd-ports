--- include/swoole_socket.h.orig	2021-07-16 07:18:11 UTC
+++ include/swoole_socket.h
@@ -17,6 +17,7 @@
 
 #pragma once
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/uio.h>
