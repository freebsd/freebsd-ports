--- TCPstream.cc.orig	Wed Mar 17 10:34:32 2004
+++ TCPstream.cc	Wed Mar 17 10:34:50 2004
@@ -44,7 +44,7 @@
 {
                                 // Convertion between the host and the network
                                 // byte orders
-#if !defined(htons) && !defined(linux)
+#if !defined(htons) && !defined(linux) && !defined(_MACHINE_ENDIAN_H_)
 unsigned short htons(unsigned int data);        // For a short data item
 unsigned short ntohs(unsigned int data);        // For a short data item
 unsigned long  htonl(unsigned long data);       // For a long data item
