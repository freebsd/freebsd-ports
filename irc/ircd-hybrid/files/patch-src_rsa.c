--- src/rsa.c.orig	2013-06-23 19:49:22.000000000 +0200
+++ src/rsa.c	2015-02-27 12:59:00.657877635 +0100
@@ -68,12 +68,6 @@
 int
 get_randomness(unsigned char *buf, int length)
 {
-  /* Seed OpenSSL PRNG with EGD enthropy pool -kre */
-  if (ConfigFileEntry.use_egd &&
-      ConfigFileEntry.egdpool_path)
-    if (RAND_egd(ConfigFileEntry.egdpool_path) == -1)
-      return -1;
-
   if (RAND_status())
     return RAND_bytes(buf, length);
   /* XXX - abort? */
