commit 1de6bbc10872b67f9f54a2511e6750a6071f5544
Author: Simon Kelley <simon@thekelleys.org.uk>
Date:   Fri Mar 19 22:24:08 2021 +0000

    Fix FTBS on FreeBSD due to Linux-specific optimisation of if_nametoindex()

diff --git a/src/network.c b/src/network.c
index cca6ff2..b4a8d7d 100644
--- a/src/network.c
+++ b/src/network.c
@@ -720,13 +720,17 @@ int enumerate_interfaces(int reset)
      to a server is specified by an interface, so cache them.
      Update the cache here. */
   for (serv = daemon->servers; serv; serv = serv->next)
-    if (strlen(serv->interface) != 0)
+    if (serv->interface[0] != 0)
       {
-	 struct ifreq ifr;
-
-	 safe_strncpy(ifr.ifr_name, serv->interface, IF_NAMESIZE);
-	 if (ioctl(param.fd, SIOCGIFINDEX, &ifr) != -1) 
-	   serv->ifindex = ifr.ifr_ifindex;
+#ifdef HAVE_LINUX_NETWORK
+	struct ifreq ifr;
+	
+	safe_strncpy(ifr.ifr_name, serv->interface, IF_NAMESIZE);
+	if (ioctl(param.fd, SIOCGIFINDEX, &ifr) != -1) 
+	  serv->ifindex = ifr.ifr_ifindex;
+#else
+	serv->ifindex = if_nametoindex(serv->interface);
+#endif
       }
     
 again:
