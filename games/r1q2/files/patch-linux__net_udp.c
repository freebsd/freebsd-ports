--- linux/net_udp.c.orig	Fri Jan 12 23:46:14 2007
+++ linux/net_udp.c	Fri Jan 12 23:59:49 2007
@@ -13,8 +13,12 @@
 #include <sys/uio.h>
 #include <errno.h>
 
+#ifdef __linux__
 #include <linux/types.h>
 #include <linux/errqueue.h>
+#else
+#include <sys/types.h>
+#endif
 
 #ifdef NeXT
 #include <libc.h>
@@ -187,6 +191,7 @@
 
 	if (ret == -1)
 	{
+#ifdef __linux__
 		//linux makes this needlessly complex, couldn't just return the source of the error in from, oh no...
 		struct probehdr	rcvbuf;
 		struct iovec	iov;
@@ -308,9 +313,10 @@
 					continue;
 			}
 		}
-
-		//errno = err;
-		//Com_Printf ("NET_GetPacket: %s\n", LOG_NET, NET_ErrorString());
+#else
+		errno = err;
+		Com_Printf ("NET_GetPacket: %s\n", LOG_NET, NET_ErrorString());
+#endif
 		return 0;
 	}
 
@@ -426,6 +432,7 @@
 		return 0;
 	}
 
+#ifdef __linux__
 	// r1: accept icmp unreachables for quick disconnects
 	if (!net_no_recverr->intvalue)
 	{
@@ -434,6 +441,7 @@
 			Com_Printf ("UDP_OpenSocket: Couldn't set IP_RECVERR: %s\n", LOG_NET, NET_ErrorString());
 		}
 	}
+#endif
 
 	if (!net_interface || !net_interface[0] || !Q_stricmp(net_interface, "localhost"))
 		address.sin_addr.s_addr = INADDR_ANY;
