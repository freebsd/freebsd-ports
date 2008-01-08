--- gnuradio-core/src/lib/io/gr_udp_source.h.orig	2007-11-05 19:55:38.000000000 -0500
+++ gnuradio-core/src/lib/io/gr_udp_source.h	2008-01-03 18:23:55.000000000 -0500
@@ -27,6 +27,10 @@
 #include <omnithread.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 
 class gr_udp_source;
 typedef boost::shared_ptr<gr_udp_source> gr_udp_source_sptr;
@@ -62,8 +66,11 @@
   int            d_socket_rcv;    // handle to socket retuned in the accept call
   struct in_addr d_ip_src;        // store the source IP address to use
   unsigned short d_port_src;      // the port number to open for connections to this service
+#ifdef BSD
+  struct sockaddr_in    d_sockaddr_src;  // store the source sockaddr data (formatted IP address and port number)
+#else
   sockaddr_in    d_sockaddr_src;  // store the source sockaddr data (formatted IP address and port number)
-
+#endif
   char *d_temp_buff;    // hold buffer between calls
   ssize_t d_residual;   // hold information about number of bytes stored in the temp buffer
   size_t d_temp_offset; // point to temp buffer location offset
