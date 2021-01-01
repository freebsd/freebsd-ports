--- src/Lib/Network/Address.hpp.orig	2016-04-09 13:14:00 UTC
+++ src/Lib/Network/Address.hpp
@@ -62,7 +62,7 @@ class Address (public)
     struct sockaddr * getSockaddr() const { return (struct sockaddr *)&ss; };
     socklen_t getSockaddrLen() const
     {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
         return sizeof(sockaddr_in); 
 #else
         return ss_len;
