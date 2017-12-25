--- jdk/src/solaris/native/java/net/NetworkInterface.c.orig	2017-12-24 22:01:27.592305000 -0800
+++ jdk/src/solaris/native/java/net/NetworkInterface.c	2017-12-24 22:06:51.899725000 -0800
@@ -2075,10 +2075,6 @@
         if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family != AF_INET6)
             continue;
 
-        // set scope ID to interface index
-        ((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_scope_id =
-            getIndex(sock, ifa->ifa_name);
-
         // add interface to the list
         ifs = addif(env, sock, ifa->ifa_name, ifs, ifa->ifa_addr, NULL,
                     AF_INET6,
