--- iodev/eth_vde.cc.orig	Sat Dec 10 16:37:35 2005
+++ iodev/eth_vde.cc	Sat Mar 18 00:25:18 2006
@@ -41,18 +41,22 @@
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
 #include <unistd.h>
-#include <stdint.h>
+#include <inttypes.h>
 
 #define SWITCH_MAGIC 0xfeedface
 
