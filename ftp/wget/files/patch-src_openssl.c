--- src/openssl.c.orig	2014-10-27 08:15:33 UTC
+++ src/openssl.c
@@ -89,9 +89,11 @@ init_prng (void)
   if (RAND_status ())
     return;
 
+#ifdef HAVE_SSL_RAND_EGD
   /* Get random data from EGD if opt.egd_file was used.  */
   if (opt.egd_file && *opt.egd_file)
     RAND_egd (opt.egd_file);
+#endif
 
   if (RAND_status ())
     return;
