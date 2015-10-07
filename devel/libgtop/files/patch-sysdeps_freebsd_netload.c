--- sysdeps/freebsd/netload.c.orig	2015-08-17 20:59:37.000000000 +0200
+++ sysdeps/freebsd/netload.c	2015-08-28 09:50:02.522090000 +0200
@@ -1,7 +1,9 @@
 /* Copyright (C) 1998-99 Martin Baulig
+   Copyright (C) 2014 Gleb Smirnoff
    This file is part of LibGTop 1.0.
 
    Contributed by Martin Baulig <martin@home-of-linux.org>, October 1998.
+   Contributed by Gleb Smirnoff <glebius@FreeBSD.org>, September 2014
 
    LibGTop is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
@@ -26,22 +28,12 @@
 
 #include <glibtop_suid.h>
 
-#include <string.h>
-
-#include <sys/types.h>
-#include <sys/socket.h>
 #include <sys/ioctl.h>
-
+#include <sys/sockio.h>
+#include <netinet/in.h>
 #include <net/if.h>
 #include <net/if_dl.h>
-#include <net/if_types.h>
-
-#ifdef HAVE_NET_IF_VAR_H
-#include <net/if_var.h>
-#endif
-
-#include <netinet/in.h>
-#include <netinet/in_var.h>
+#include <ifaddrs.h>
 
 static const unsigned long _glibtop_sysdeps_netload =
 (1L << GLIBTOP_NETLOAD_IF_FLAGS) +
@@ -64,24 +56,11 @@ static const unsigned long _glibtop_sysd
 (1L << GLIBTOP_NETLOAD_ADDRESS6) +
 (1L << GLIBTOP_NETLOAD_SCOPE6);
 
-/* nlist structure for kernel access */
-static struct nlist nlst [] =
-        {
-                { "_ifnet"
-                },
-                { 0 }
-        };
-
 /* Init function. */
 
 void
 _glibtop_init_netload_p (glibtop *server)
 {
-        if (kvm_nlist (server->machine->kd, nlst) < 0) {
-                glibtop_warn_io_r (server, "kvm_nlist");
-		return;
-	}
-
 	server->sysdeps.netload = _glibtop_sysdeps_netload;
 }
 
@@ -91,154 +70,125 @@ void
 glibtop_get_netload_p (glibtop *server, glibtop_netload *buf,
                        const char *interface)
 {
-        struct ifnet ifnet;
-        u_long ifnetaddr;
-        struct sockaddr *sa = NULL;
-
-        union {
-                struct ifaddr ifa;
-                struct in_ifaddr in;
-        } ifaddr;
+        struct ifaddrs *ifap, *ifa;
 
         memset (buf, 0, sizeof (glibtop_netload));
 
-	if (server->sysdeps.netload == 0) return;
+	if (server->sysdeps.netload == 0)
+                return;
+
+        if (getifaddrs(&ifap) != 0) {
+                glibtop_warn_io_r (server, "getifaddrs");
+                return;
+        }
 
-        if (kvm_read (server->machine->kd, nlst [0].n_value,
-                        &ifnetaddr, sizeof (ifnetaddr)) != sizeof (ifnetaddr)) {
-                glibtop_warn_io_r (server, "kvm_read (ifnet)");
-		return;
-	}
-
-        for (/* NOP */; ifnetaddr; ifnetaddr = (u_long) ifnet.if_link.tqe_next)
-        {
-                struct sockaddr_in *sin;
-                register char *cp;
-                u_long ifaddraddr;
-
-		if (kvm_read (server->machine->kd, ifnetaddr, &ifnet,
-			      sizeof (ifnet)) != sizeof (ifnet)) {
-			glibtop_warn_io_r (server,
-					   "kvm_read (ifnetaddr)");
-			break;
-		}
+#define	IFA_STAT(s)	(((struct if_data *)ifa->ifa_data)->ifi_ ## s)
 
-		if (strcmp (ifnet.if_xname, interface) != 0)
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+	        if (strcmp (ifa->ifa_name, interface) != 0)
 			continue;
-		
-	        if (ifnet.if_flags & IFF_UP)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_UP);
-                if (ifnet.if_flags & IFF_BROADCAST)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_BROADCAST);
-                if (ifnet.if_flags & IFF_DEBUG)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_DEBUG);
-                if (ifnet.if_flags & IFF_LOOPBACK)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LOOPBACK);
-                if (ifnet.if_flags & IFF_POINTOPOINT)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_POINTOPOINT);
-#ifdef IFF_DRV_RUNNING
-                if (ifnet.if_drv_flags & IFF_DRV_RUNNING)
-#else
-                if (ifnet.if_flags & IFF_RUNNING)
-#endif
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_RUNNING);
-                if (ifnet.if_flags & IFF_NOARP)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_NOARP);
-                if (ifnet.if_flags & IFF_PROMISC)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_PROMISC);
-                if (ifnet.if_flags & IFF_ALLMULTI)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALLMULTI);
-#ifdef IFF_DRV_OACTIVE
-                if (ifnet.if_drv_flags & IFF_DRV_OACTIVE)
-#else
-                if (ifnet.if_flags & IFF_OACTIVE)
-#endif
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_OACTIVE);
-                if (ifnet.if_flags & IFF_SIMPLEX)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_SIMPLEX);
-                if (ifnet.if_flags & IFF_LINK0)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK0);
-                if (ifnet.if_flags & IFF_LINK1)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK1);
-                if (ifnet.if_flags & IFF_LINK2)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK2);
-                if (ifnet.if_flags & IFF_ALTPHYS)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALTPHYS);
-                if (ifnet.if_flags & IFF_MULTICAST)
-                        buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_MULTICAST);
-
-                buf->packets_in = ifnet.if_ipackets;
-                buf->packets_out = ifnet.if_opackets;
-                buf->packets_total = buf->packets_in + buf->packets_out;
-
-                buf->bytes_in = ifnet.if_ibytes;
-                buf->bytes_out = ifnet.if_obytes;
-                buf->bytes_total = buf->bytes_in + buf->bytes_out;
-
-                buf->errors_in = ifnet.if_ierrors;
-                buf->errors_out = ifnet.if_oerrors;
-                buf->errors_total = buf->errors_in + buf->errors_out;
-
-                buf->collisions = ifnet.if_collisions;
-                buf->flags = _glibtop_sysdeps_netload;
-
-                for (ifaddraddr = (u_long) ifnet.if_addrhead.tqh_first; ifaddraddr; ifaddraddr = (u_long) ifaddr.ifa.ifa_link.tqe_next) {
-                        if ((kvm_read (server->machine->kd, ifaddraddr, &ifaddr,
-                                        sizeof (ifaddr)) != sizeof (ifaddr))) {
-                                glibtop_warn_io_r (server,
-						   "kvm_read (ifaddraddr)");
-				break;
-			}
-
-#define CP(x) ((char *)(x))
-                        cp = (CP(ifaddr.ifa.ifa_addr) - CP(ifaddraddr)) +
-                             CP(&ifaddr);
-                        sa = (struct sockaddr *)cp;
-
-                        if (sa->sa_family == AF_LINK) {
-                                struct sockaddr_dl *dl = (struct sockaddr_dl *) sa;
-
-                                memcpy (buf->hwaddress, LLADDR (dl),
-					sizeof (buf->hwaddress));
-                                buf->flags |= GLIBTOP_NETLOAD_HWADDRESS;
-                        } else if (sa->sa_family == AF_INET) {
-                                sin = (struct sockaddr_in *)sa;
-                                /* Commenting out to "fix" #13345. */
-                                buf->subnet = htonl (ifaddr.in.ia_subnet);
-                                buf->address = sin->sin_addr.s_addr;
-                                buf->mtu = ifnet.if_mtu;
-
-                                buf->flags |= _glibtop_sysdeps_netload_data;
-                        } else if (sa->sa_family == AF_INET6) {
-                                struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) sa;
-                                int in6fd;
-
-                                memcpy (buf->address6, &sin6->sin6_addr,
-					sizeof (buf->address6));
-                                buf->scope6 = (guint8) sin6->sin6_scope_id;
-                                buf->flags |= _glibtop_sysdeps_netload6;
-
-                                in6fd = socket (AF_INET6, SOCK_DGRAM, 0);
-                                if (in6fd >= 0) {
-                                        struct in6_ifreq ifr;
-
-                                        memset (&ifr, 0, sizeof (ifr));
-                                        ifr.ifr_addr = *sin6;
-                                        g_strlcpy (ifr.ifr_name, interface,
-                                                   sizeof (ifr.ifr_name));
-                                        if (ioctl (in6fd, SIOCGIFNETMASK_IN6,
-						  (char *) &ifr) >= 0) {
-                                                memcpy (buf->prefix6,
-						        &ifr.ifr_addr.sin6_addr,
-                                                        sizeof (buf->prefix6));
-                                                buf->flags |= GLIBTOP_NETLOAD_PREFIX6;
-                                        }
-                                        close (in6fd);
-                                }
-                        }
-                } /* end of for ( ifaddraddr ) */
 
-		/* found the interface anyway */
-                break;
-        } /* end of for ( ifnetaddr ) */
+		switch (ifa->ifa_addr->sa_family) {
+                case AF_LINK: {
+                        struct sockaddr_dl *sdl;
+                        struct ifreq ifr;
+                        int s, flags;
+
+                        s = socket(AF_INET, SOCK_DGRAM, 0);
+                        if (s < 0) {
+                                glibtop_warn_io_r(server, "socket(AF_INET)");
+                                break;
+                        }
+                        memset(&ifr, 0, sizeof(ifr));
+                        (void)strlcpy(ifr.ifr_name, ifa->ifa_name,
+                                sizeof(ifr.ifr_name));
+                        if (ioctl(s, SIOCGIFFLAGS, (caddr_t)&ifr) < 0) {
+                                glibtop_warn_io_r(server, "ioctl(SIOCGIFFLAGS)");
+                                close(s);
+                                break;
+                        }
+                        close(s);
+ 
+                        flags = (ifr.ifr_flags & 0xffff) | (ifr.ifr_flagshigh << 16);
+
+                        if (flags & IFF_UP)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_UP);
+                        if (flags & IFF_BROADCAST)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_BROADCAST);
+                        if (flags & IFF_DEBUG)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_DEBUG);
+                        if (flags & IFF_LOOPBACK)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LOOPBACK);
+                        if (flags & IFF_POINTOPOINT)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_POINTOPOINT);
+                        if (flags & IFF_RUNNING)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_RUNNING);
+                        if (flags & IFF_NOARP)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_NOARP);
+                        if (flags & IFF_PROMISC)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_PROMISC);
+                        if (flags & IFF_ALLMULTI)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALLMULTI);
+                        if (flags & IFF_SIMPLEX)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_SIMPLEX);
+                        if (flags & IFF_LINK0)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK0);
+                        if (flags & IFF_LINK1)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK1);
+                        if (flags & IFF_LINK2)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK2);
+                        if (flags & IFF_ALTPHYS)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALTPHYS);
+                        if (flags & IFF_MULTICAST)
+                                buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_MULTICAST);
+
+                        buf->packets_in = IFA_STAT(ipackets);
+                        buf->packets_out = IFA_STAT(opackets);
+                        buf->packets_total = buf->packets_in + buf->packets_out;
+
+                        buf->bytes_in = IFA_STAT(ibytes);
+                        buf->bytes_out = IFA_STAT(obytes);
+                        buf->bytes_total = buf->bytes_in + buf->bytes_out;
+
+                        buf->errors_in = IFA_STAT(ierrors);
+                        buf->errors_out = IFA_STAT(oerrors);
+                        buf->errors_total = buf->errors_in + buf->errors_out;
+
+                        buf->collisions = IFA_STAT(collisions);
+                        buf->flags = _glibtop_sysdeps_netload;
+
+                        sdl = (struct sockaddr_dl *)ifa->ifa_addr;
+                        memcpy(buf->hwaddress, LLADDR(sdl),
+                                sizeof(buf->hwaddress));
+                        buf->mtu = IFA_STAT(mtu);
+                        buf->flags |= GLIBTOP_NETLOAD_HWADDRESS;
+                        break;
+                }
+                case AF_INET: {
+                        struct sockaddr_in *sin;
+
+                        sin = (struct sockaddr_in *)ifa->ifa_addr;
+                        buf->address = sin->sin_addr.s_addr;
+                        sin = (struct sockaddr_in *)ifa->ifa_netmask;
+                        buf->subnet = sin->sin_addr.s_addr & buf->address;
+                        buf->flags |= _glibtop_sysdeps_netload_data;
+                        break;
+                }
+                case AF_INET6: {
+                        struct sockaddr_in6 *sin6;
+
+                        sin6 = (struct sockaddr_in6 *)ifa->ifa_addr;
+                        memcpy(buf->address6, &sin6->sin6_addr,
+                                sizeof(buf->address6));
+                        buf->scope6 = (guint8 )sin6->sin6_scope_id;
+                        buf->flags |= _glibtop_sysdeps_netload6;
+                        sin6 = (struct sockaddr_in6 *)ifa->ifa_netmask;
+                        memcpy(buf->prefix6, &sin6->sin6_addr,
+                                sizeof(buf->prefix6));
+                        buf->flags |= GLIBTOP_NETLOAD_PREFIX6;
+                        break;
+                }
+                } // switch() end
+        }
+        freeifaddrs(ifap);
 }
