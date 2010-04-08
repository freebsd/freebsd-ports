--- contrib/mod_sftp/scp.c.orig	2010-04-08 16:50:19.950294512 +0200
+++ contrib/mod_sftp/scp.c	2010-04-08 16:50:34.925959239 +0200
@@ -1772,7 +1772,7 @@
    */
 
 #if defined(FREEBSD4) || defined(FREEBSD5) || defined(FREEBSD6) || \
-    defined(FREEBSD7) || \
+    defined(FREEBSD7) || defined(FREEBSD8) || defined(FREEBSD9) || \
     defined(DARWIN7) || defined(DARWIN8) || defined(DARWIN9)
   optreset = 1;
   opterr = 1;
