--- gnuradio-core/src/lib/io/gr_udp_sink.h.orig	2008-01-03 15:48:59.000000000 -0500
+++ gnuradio-core/src/lib/io/gr_udp_sink.h	2008-01-03 18:19:32.000000000 -0500
@@ -27,6 +27,11 @@
 #include <omnithread.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 
 class gr_udp_sink;
 typedef boost::shared_ptr<gr_udp_sink> gr_udp_sink_sptr;
@@ -70,8 +75,13 @@
   struct in_addr d_ip_dst;          // store the destination ip info
   unsigned short d_port_src;        // the port number to open for connections to this service
   unsigned short d_port_dst;        // port number of the remove system
+#ifdef BSD
+  struct sockaddr_in    d_sockaddr_src;    // store the source sockaddr data (formatted IP address and port number)
+  struct sockaddr_in    d_sockaddr_dst;    // store the destination sockaddr data (formatted IP address and port number)
+#else
   sockaddr_in    d_sockaddr_src;    // store the source sockaddr data (formatted IP address and port number)
   sockaddr_in    d_sockaddr_dst;    // store the destination sockaddr data (formatted IP address and port number)
+#endif
 
  protected:
   /*!
