--- src/global.c.orig	Tue May 29 21:02:46 2001
+++ src/global.c	Tue May 29 21:02:57 2001
@@ -2734,7 +2734,7 @@
   global.auto_save = NULL;
   global.execs = NULL;
   global.pings = NULL;
-  global.ping_command = strdup("/bin/ping -c 3 $IP");
+  global.ping_command = strdup("/sbin/ping -c 3 $IP");
 
   global.browse_width[0] = 369;
   global.browse_width[1] = 80;
