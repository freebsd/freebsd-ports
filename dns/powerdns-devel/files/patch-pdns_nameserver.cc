--- pdns/nameserver.cc.orig	Sun Nov 19 16:09:10 2006
+++ pdns/nameserver.cc	Sun Nov 19 16:10:28 2006
@@ -145,9 +145,9 @@
     }
 
     sockaddr_in6 locala;
-    locala.sin6_port=ntohs(arg().asNum("local-port"));
+    memset(&locala, 0, sizeof(locala));
+    locala.sin6_port=htons(arg().asNum("local-port"));
     locala.sin6_family=AF_INET6;
-    locala.sin6_flowinfo=0;
 
     if(!inet_pton(AF_INET6, localname.c_str(), (void *)&locala.sin6_addr)) {
       addrinfo *addrinfos;
