--- linux/net_udp.c.orig	Fri Dec 29 17:10:28 2006
+++ linux/net_udp.c	Fri Dec 29 17:11:42 2006
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
@@ -191,6 +195,7 @@
 
 		if (err == ECONNREFUSED)
 		{
+#ifdef __linux__
 			//linux makes this needlessly complex, couldn't just return the source of the error in from, oh no...
 			struct probehdr	rcvbuf;
 			struct iovec	iov;
@@ -243,6 +248,11 @@
 			}
 
 			return 0;
+#else
+			SockadrToNetadr (&from, net_from);
+			Com_Printf ("NET_GetPacket: %s from %s\n", LOG_NET, NET_ErrorString(), NET_AdrToString (net_from));
+			return -1;
+#endif
 		}
 		Com_Printf ("NET_GetPacket: %s\n", LOG_NET, NET_ErrorString());
 		return 0;
@@ -359,11 +369,13 @@
 		return 0;
 	}
 
+#ifdef __linux__
 	// r1: accept icmp unreachables for quick disconnects
 	if (setsockopt (newsocket, IPPROTO_IP, IP_RECVERR, (char *)&i, sizeof(i)) == -1)
 	{
 		Com_Printf ("UDP_OpenSocket: Couldn't set IP_RECVERR: %s\n", LOG_NET, NET_ErrorString());
 	}
+#endif
 
 	if (!net_interface || !net_interface[0] || !Q_stricmp(net_interface, "localhost"))
 		address.sin_addr.s_addr = INADDR_ANY;
