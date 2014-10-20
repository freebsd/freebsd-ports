--- sysdeps/freebsd/netload.c.orig	2013-11-13 14:46:58.000000000 -0500
+++ sysdeps/freebsd/netload.c	2013-11-13 15:01:52.000000000 -0500
@@ -37,6 +37,7 @@
 #include <net/if_types.h>
 
 #ifdef HAVE_NET_IF_VAR_H
+#define _WANT_IFADDR 1
 #include <net/if_var.h>
 #endif
 
@@ -116,7 +117,7 @@ glibtop_get_netload_p (glibtop *server, 
         while (ifnetaddr)
         {
                 struct sockaddr_in *sin;
-                register char *cp;
+                register uint8_t *cp;
                 u_long ifaddraddr;
 
                 {
@@ -201,10 +202,10 @@ glibtop_get_netload_p (glibtop *server, 
 				continue;
 			}
 
-#define CP(x) ((char *)(x))
+#define CP(x) ((uint8_t *)(x))
                         cp = (CP(ifaddr.ifa.ifa_addr) - CP(ifaddraddr)) +
                              CP(&ifaddr);
-                        sa = (struct sockaddr *)cp;
+                        sa = (struct sockaddr *) cp;
 
                         if (sa->sa_family == AF_LINK) {
                                 struct sockaddr_dl *dl = (struct sockaddr_dl *) sa;
