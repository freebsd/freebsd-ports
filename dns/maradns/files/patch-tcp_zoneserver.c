--- tcp/zoneserver.c.orig	2009-09-23 02:00:29.000000000 +0200
+++ tcp/zoneserver.c	2009-09-23 02:03:05.000000000 +0200
@@ -1014,7 +1014,7 @@
     js_string *synth_soa_origin;
 
     /* Kill children processes when we are signaled */
-    if(setpgrp()) {
+    if(setpgrp(0, 0)) {
         printf(strerror(errno)); /* harderror() would kill the group which may not be correct yet */
         return 3;
     }
