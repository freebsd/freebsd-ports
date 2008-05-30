--- lib/voodoo/manager.c.orig	2007-12-15 14:30:28.000000000 +0200
+++ lib/voodoo/manager.c	2008-03-16 14:51:33.000000000 +0200
@@ -186,7 +186,7 @@
 
      D_DEBUG( "Voodoo/Manager: Creating manager at %p.\n", manager );
 
-     if (setsockopt( fd, SOL_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
+     if (setsockopt( fd, IPPROTO_IP, IP_TOS, &tos, sizeof(tos) ) < 0)
           D_PERROR( "Voodoo/Manager: Could not set IP_TOS!\n" );
 
      if (setsockopt( fd, SOL_TCP, TCP_NODELAY, &one, sizeof(one) ) < 0)
