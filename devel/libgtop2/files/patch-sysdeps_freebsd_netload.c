--- sysdeps/freebsd/netload.c.orig	Mon Oct 20 01:55:32 2003
+++ sysdeps/freebsd/netload.c	Fri Nov 14 23:09:15 2003
@@ -83,6 +83,7 @@
     u_long ifnetaddr, ifnetfound, ifaddraddr;
     struct sockaddr *sa;
     char tname [16];
+    char temp [16];
 
     union {
 	struct ifaddr ifa;
@@ -109,10 +110,13 @@
 			  sizeof (ifnet)) != sizeof (ifnet))
 		    glibtop_error_io_r (server, "kvm_read (ifnetaddr)");
 
-#if defined(__FreeBSD__) || defined(__bsdi__)
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 501113)) || defined(__bsdi__)
 	    if (kvm_read (server->machine.kd, (u_long) ifnet.if_name,
 			  tname, 16) != 16)
 		    glibtop_error_io_r (server, "kvm_read (if_name)");
+	    snprintf(temp, (15 - strlen(tname)), "%d", ifnet.if_unit);
+	    strcat(tname, temp);
+	    tname [15] = 0;
 #else
 	    strncpy (tname, ifnet.if_xname, 16);
 	    tname [15] = 0;
@@ -140,39 +144,39 @@
 		sin = (struct sockaddr_in *)sa;
 
 		if (ifnet.if_flags & IFF_UP)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_UP;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_UP);
 		if (ifnet.if_flags & IFF_BROADCAST)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_BROADCAST;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_BROADCAST);
 		if (ifnet.if_flags & IFF_DEBUG)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_DEBUG;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_DEBUG);
 		if (ifnet.if_flags & IFF_LOOPBACK)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_LOOPBACK;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LOOPBACK);
 		if (ifnet.if_flags & IFF_POINTOPOINT)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_POINTOPOINT;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_POINTOPOINT);
 		if (ifnet.if_flags & IFF_RUNNING)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_RUNNING;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_RUNNING);
 		if (ifnet.if_flags & IFF_NOARP)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_NOARP;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_NOARP);
 		if (ifnet.if_flags & IFF_PROMISC)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_PROMISC;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_PROMISC);
 		if (ifnet.if_flags & IFF_ALLMULTI)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_ALLMULTI;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALLMULTI);
 		if (ifnet.if_flags & IFF_OACTIVE)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_OACTIVE;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_OACTIVE);
 		if (ifnet.if_flags & IFF_SIMPLEX)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_SIMPLEX;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_SIMPLEX);
 		if (ifnet.if_flags & IFF_LINK0)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_LINK0;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK0);
 		if (ifnet.if_flags & IFF_LINK1)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_LINK1;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK1);
 		if (ifnet.if_flags & IFF_LINK2)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_LINK2;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK2);
 #ifdef __FreeBSD__
 		if (ifnet.if_flags & IFF_ALTPHYS)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_ALTPHYS;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALTPHYS);
 #endif
 		if (ifnet.if_flags & IFF_MULTICAST)
-			buf->if_flags |= GLIBTOP_IF_FLAGS_MULTICAST;
+			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_MULTICAST);
 
 #if !defined(__bsdi__)
 		/* Commenting out to "fix" #13345. */
