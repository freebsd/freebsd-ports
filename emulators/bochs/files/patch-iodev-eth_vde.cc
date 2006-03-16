--- iodev/eth_vde.cc.orig	Sat Dec 10 12:37:35 2005
+++ iodev/eth_vde.cc	Thu Mar 16 13:02:15 2006
@@ -41,13 +41,17 @@
 #include <sys/poll.h>
 #include <sys/time.h>
 #include <sys/resource.h>
-#include <asm/types.h>
 #include <sys/socket.h>
 #include <sys/uio.h>
 #include <sys/wait.h>
 #include <sys/un.h>
+#if defined(__linux__)
+#include <asm/types.h>
 #include <linux/netlink.h>
 #include <linux/if.h>
+#elif BX_HAVE_NET_IF_H
+#include <net/if.h>
+#endif
 #include <assert.h>
 #include <fcntl.h>
 #include <errno.h>
