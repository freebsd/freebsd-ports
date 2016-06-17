--- lib/voodoo/manager.c.orig	2012-05-23 13:43:12 UTC
+++ lib/voodoo/manager.c
@@ -41,6 +41,7 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 
+#include <netinet/in_systm.h> /* for n_long, required for build on 7.x */
 #include <netinet/in.h>
 #if !VOODOO_BUILD_NO_SETSOCKOPT
 #include <netinet/ip.h>
@@ -193,10 +194,10 @@ voodoo_manager_create( int             f
      D_DEBUG( "Voodoo/Manager: Creating manager at %p.\n", manager );
 
 #if !VOODOO_BUILD_NO_SETSOCKOPT
-     if (setsockopt( fd, SOL_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
+     if (setsockopt( fd, IPPROTO_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
           D_PERROR( "Voodoo/Manager: Could not set IP_TOS!\n" );
 
-     if (setsockopt( fd, SOL_TCP, TCP_NODELAY, &one, sizeof(one) ) < 0)
+     if (setsockopt( fd, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one) ) < 0)
           D_PERROR( "Voodoo/Manager: Could not set TCP_NODELAY!\n" );
 #endif
 
