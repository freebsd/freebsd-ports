--- contrib/mod_ban.c.orig	2010-04-08 16:31:51.305526124 +0200
+++ contrib/mod_ban.c	2010-04-08 16:32:29.115825094 +0200
@@ -1117,6 +1117,7 @@
 
 #if defined(FREEBSD4) || defined(FREEBSD5) || \
     defined(FREEBSD6) || defined(FREEBSD7) || \
+    defined(FREEBSD8) || defined(FREEBSD9) || \
     defined(DARWIN7) || defined(DARWIN8) || defined(DARWIN9)
     optreset = 1;
     opterr = 1;
