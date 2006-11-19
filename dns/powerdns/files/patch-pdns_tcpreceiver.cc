--- pdns/tcpreceiver.cc.orig	Sun Nov 19 16:11:25 2006
+++ pdns/tcpreceiver.cc	Sun Nov 19 16:13:27 2006
@@ -480,10 +480,9 @@
       throw AhuException("Unable to acquire TCPv6 socket: "+stringerror());
 
     sockaddr_in6 locala;
-    locala.sin6_port=ntohs(arg().asNum("local-port"));
+    memset(&locala, 0, sizeof(locala));
+    locala.sin6_port=htons(arg().asNum("local-port"));
     locala.sin6_family=AF_INET6;
-    locala.sin6_flowinfo=0;
-
 
     if(!inet_pton(AF_INET6, laddr->c_str(), (void *)&locala.sin6_addr)) {
       addrinfo *addrinfos;
