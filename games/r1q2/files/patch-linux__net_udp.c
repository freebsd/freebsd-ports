--- linux/net_udp.c.orig	Sun Jan 14 16:56:54 2007
+++ linux/net_udp.c	Sun Jan 14 18:17:28 2007
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
@@ -308,9 +313,19 @@
 					continue;
 			}
 		}
+#else
+		err = errno;
 
-		//errno = err;
-		//Com_Printf ("NET_GetPacket: %s\n", LOG_NET, NET_ErrorString());
+		if (err == EWOULDBLOCK)
+			return 0;
+		if (err == ECONNREFUSED)
+		{
+			SockadrToNetadr (&from, net_from);
+			Com_Printf ("NET_GetPacket: %s from %s\n", LOG_NET, NET_ErrorString(), NET_AdrToString (net_from));
+			return -1;
+		}
+		Com_Printf ("NET_GetPacket: %s\n", LOG_NET, NET_ErrorString());
+#endif
 		return 0;
 	}
 
@@ -426,6 +441,7 @@
 		return 0;
 	}
 
+#ifdef __linux__
 	// r1: accept icmp unreachables for quick disconnects
 	if (!net_no_recverr->intvalue)
 	{
@@ -434,6 +450,7 @@
 			Com_Printf ("UDP_OpenSocket: Couldn't set IP_RECVERR: %s\n", LOG_NET, NET_ErrorString());
 		}
 	}
+#endif
 
 	if (!net_interface || !net_interface[0] || !Q_stricmp(net_interface, "localhost"))
 		address.sin_addr.s_addr = INADDR_ANY;
