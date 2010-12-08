--- ./lib/voodoo/manager.c.orig	2010-11-02 00:11:20.000000000 +0100
+++ ./lib/voodoo/manager.c	2010-12-03 16:44:12.000000000 +0100
@@ -41,6 +41,7 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 
+#include <netinet/in_systm.h> /* for n_long, required for build on 7.x */
 #include <netinet/in.h>
 #if !VOODOO_BUILD_NO_SETSOCKOPT
 #include <netinet/ip.h>
@@ -193,10 +194,10 @@
      D_DEBUG( "Voodoo/Manager: Creating manager at %p.\n", manager );
 
 #if !VOODOO_BUILD_NO_SETSOCKOPT
-     if (setsockopt( fd, SOL_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
+     if (setsockopt( fd, IPPROTO_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
           D_PERROR( "Voodoo/Manager: Could not set IP_TOS!\n" );
 
-     if (setsockopt( fd, SOL_TCP, TCP_NODELAY, &one, sizeof(one) ) < 0)
+     if (setsockopt( fd, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one) ) < 0)
           D_PERROR( "Voodoo/Manager: Could not set TCP_NODELAY!\n" );
 #endif
 
