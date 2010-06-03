--- lib/voodoo/manager.c.orig	2009-06-02 18:47:23.000000000 +0200
+++ lib/voodoo/manager.c	2010-06-03 09:21:51.000000000 +0200
@@ -40,6 +40,7 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 
+#include <netinet/in_systm.h> /* for n_long, required for build on 7.x */
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
@@ -186,10 +187,10 @@
 
      D_DEBUG( "Voodoo/Manager: Creating manager at %p.\n", manager );
 
-     if (setsockopt( fd, SOL_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
+     if (setsockopt( fd, IPPROTO_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
           D_PERROR( "Voodoo/Manager: Could not set IP_TOS!\n" );
 
-     if (setsockopt( fd, SOL_TCP, TCP_NODELAY, &one, sizeof(one) ) < 0)
+     if (setsockopt( fd, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one) ) < 0)
           D_PERROR( "Voodoo/Manager: Could not set TCP_NODELAY!\n" );
 
      DUMP_SOCKET_OPTION( SO_SNDLOWAT );
