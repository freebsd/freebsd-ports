--- dnstracer.c.orig	Sun Jan 25 11:23:52 2004
+++ dnstracer.c	Sun Jan 25 11:24:01 2004
@@ -729,7 +729,7 @@
         hints.ai_family = PF_INET;
         hints.ai_socktype = SOCK_DGRAM;
         error = getaddrinfo(global_source_address, 0, &hints, &src_res);
-        if (error == EAI_NODATA) {
+        if (error == EAI_NONAME) {
 	    hints.ai_flags = 0;
 	    error = getaddrinfo(global_source_address, 0, &hints, &src_res);
         }
