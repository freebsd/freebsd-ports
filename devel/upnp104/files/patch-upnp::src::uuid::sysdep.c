--- upnp/src/uuid/sysdep.c.orig	Thu Jan 16 05:39:44 2003
+++ upnp/src/uuid/sysdep.c	Sat Apr  5 23:20:48 2003
@@ -144,7 +144,7 @@
 {
     MD5_CTX c;
     typedef struct {
-        struct sysinfo s;
+        //struct sysinfo s;
         struct timeval t;
         char hostname[257];
     } randomness;
