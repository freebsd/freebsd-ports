--- ./iodev/network/eth_slirp.cc.orig	2025-02-16 04:15:29.000000000 -0500
+++ ./iodev/network/eth_slirp.cc	2025-02-18 21:26:22.200515000 -0500
@@ -20,6 +20,11 @@
 // eth_slirp.cc  - Bochs port of Qemu's slirp implementation (updated from libslirp 4.8.0)
 // Portion of this software comes with the following license: BSD-3-Clause
 
+#include <netinet/in.h>
+#include <sys/socket.h>
+#include <sys/wait.h>
+#include <sys/types.h>
+
 #define BX_PLUGGABLE
 
 #ifdef __CYGWIN__
