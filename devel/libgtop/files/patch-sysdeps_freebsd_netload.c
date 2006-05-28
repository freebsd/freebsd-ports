--- sysdeps/freebsd/netload.c.orig	Mon Dec 12 05:09:39 2005
+++ sysdeps/freebsd/netload.c	Wed May  3 13:46:08 2006
@@ -28,6 +28,8 @@
 
 #include <glibtop_suid.h>
 
+#include <string.h>
+
 #include <net/if.h>
 #include <net/if_dl.h>
 #include <net/if_types.h>
@@ -83,9 +85,11 @@ glibtop_get_netload_p (glibtop *server, 
 		       const char *interface)
 {
     struct ifnet ifnet;
-    u_long ifnetaddr, ifnetfound, ifaddraddr;
+    u_long ifnetaddr, ifnetfound;
     struct sockaddr *sa = NULL;
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 501113)) || defined(__bsdi__)
     char tname [16];
+#endif
     char name [32];
 
     union {
@@ -101,12 +105,12 @@ glibtop_get_netload_p (glibtop *server, 
 		  &ifnetaddr, sizeof (ifnetaddr)) != sizeof (ifnetaddr))
 	glibtop_error_io_r (server, "kvm_read (ifnet)");
 
-    ifaddraddr = 0;
-    while (ifnetaddr || ifaddraddr) {
+    while (ifnetaddr) {
 	struct sockaddr_in *sin;
 	register char *cp;
+	u_long ifaddraddr;
 
-	if (ifaddraddr == 0) {
+	{
 	    ifnetfound = ifnetaddr;
 
 	    if (kvm_read (server->machine.kd, ifnetaddr, &ifnet,
@@ -151,7 +155,11 @@ glibtop_get_netload_p (glibtop *server, 
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LOOPBACK);
 	if (ifnet.if_flags & IFF_POINTOPOINT)
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_POINTOPOINT);
+#ifdef IFF_DRV_RUNNING
+	if (ifnet.if_drv_flags & IFF_DRV_RUNNING)
+#else
 	if (ifnet.if_flags & IFF_RUNNING)
+#endif
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_RUNNING);
 	if (ifnet.if_flags & IFF_NOARP)
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_NOARP);
@@ -159,7 +167,11 @@ glibtop_get_netload_p (glibtop *server, 
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_PROMISC);
 	if (ifnet.if_flags & IFF_ALLMULTI)
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALLMULTI);
+#ifdef IFF_DRV_OACTIVE
+	if (ifnet.if_drv_flags & IFF_DRV_OACTIVE)
+#else
 	if (ifnet.if_flags & IFF_OACTIVE)
+#endif
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_OACTIVE);
 	if (ifnet.if_flags & IFF_SIMPLEX)
 		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_SIMPLEX);
@@ -191,7 +203,7 @@ glibtop_get_netload_p (glibtop *server, 
 	buf->collisions = ifnet.if_collisions;
 	buf->flags = _glibtop_sysdeps_netload;
 
-	if (ifaddraddr) {
+	while (ifaddraddr) {
 	    if ((kvm_read (server->machine.kd, ifaddraddr, &ifaddr,
 			   sizeof (ifaddr)) != sizeof (ifaddr)))
 		glibtop_error_io_r (server, "kvm_read (ifaddraddr)");
@@ -201,7 +213,12 @@ glibtop_get_netload_p (glibtop *server, 
 		CP(&ifaddr);
 	    sa = (struct sockaddr *)cp;
 
-	    if (sa->sa_family == AF_INET) {
+	    if (sa->sa_family == AF_LINK) {
+		struct sockaddr_dl *dl = (struct sockaddr_dl *) sa;
+
+		memcpy (buf->hwaddress, LLADDR (dl), sizeof (buf->hwaddress));
+		buf->flags |= GLIBTOP_NETLOAD_HWADDRESS;
+	    } else if (sa->sa_family == AF_INET) {
 		sin = (struct sockaddr_in *)sa;
 #if !defined(__bsdi__)
 		/* Commenting out to "fix" #13345. */
@@ -211,8 +228,14 @@ glibtop_get_netload_p (glibtop *server, 
 		buf->mtu = ifnet.if_mtu;
 
 		buf->flags |= _glibtop_sysdeps_netload_data;
+	    } else if (sa->sa_family == AF_INET6) {
+		struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) sa;
 
+		memcpy (buf->address6, &sin6->sin6_addr, sizeof (buf->address6));
+		buf->flags |= GLIBTOP_NETLOAD_ADDRESS6;
 	    }
+	    /* FIXME prefix6, scope6 */
+	    ifaddraddr = (u_long) ifaddr.ifa.ifa_link.tqe_next;
 	}
 	return;
     }
