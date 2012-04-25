--- src/Lib/Network/Address.hpp.orig	2010-01-19 17:08:17.000000000 +0100
+++ src/Lib/Network/Address.hpp	2012-04-20 17:34:26.306480287 +0200
@@ -47,7 +47,7 @@
     struct sockaddr * getSockaddr() const { return (struct sockaddr *)&ss; };
     socklen_t getSockaddrLen() const
     {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
         return sizeof(sockaddr_in); 
 #else
         return ss_len;
