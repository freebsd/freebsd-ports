--- src/global.c.orig	Sun Nov  4 20:30:19 2001
+++ src/global.c	Wed Nov 28 21:52:10 2001
@@ -3597,7 +3597,7 @@
   global.auto_save = NULL;
   global.execs = NULL;
   global.pings = NULL;
-  global.ping_command = l_strdup("/bin/ping -c 3 $IP");
+  global.ping_command = l_strdup("/sbin/ping -c 3 $IP");
 
   global.browse_width[0] = 369;
   global.browse_width[1] = 80;
