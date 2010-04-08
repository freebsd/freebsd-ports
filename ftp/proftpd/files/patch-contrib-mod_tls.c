--- contrib/mod_tls.c.orig	2010-04-08 16:31:45.943822175 +0200
+++ contrib/mod_tls.c	2010-04-08 16:32:44.490058910 +0200
@@ -4812,6 +4812,7 @@
   /* All the fun portability of resetting getopt(3). */
 #if defined(FREEBSD4) || defined(FREEBSD5) || \
     defined(FREEBSD6) || defined(FREEBSD7) || \
+    defined(FREEBSD8) || defined(FREEBSD9) || \
     defined(DARWIN7) || defined(DARWIN8) || defined(DARWIN9)
   optreset = 1;
   opterr = 1;
