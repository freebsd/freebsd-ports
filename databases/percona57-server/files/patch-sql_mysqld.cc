--- sql/mysqld.cc.orig	2022-08-05 18:25:13 UTC
+++ sql/mysqld.cc
@@ -1531,6 +1531,16 @@ static void clean_up_mutexes()
 ****************************************************************************/
 
 /* Initialise proxy protocol. */
+
+/* At least OpenBSD and NexentaCore do not
+* define s6_addr32 for user land settings.
+*/
+#if !defined s6_addr32 && defined __sun__
+#       define s6_addr32 _S6_un._S6_u32
+#elif !defined s6_addr32 && ( defined __OpenBSD__ || defined __FreeBSD__ )
+#       define s6_addr32 __u6_addr.__u6_addr32
+#endif  /* !defined s6_addr32 */
+
 static void set_proxy()
 {
   const char *p;
@@ -3706,6 +3716,7 @@ static int init_ssl()
 static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
+#ifndef LIBRESSL_VERSION_NUMBER
 
 #if OPENSSL_VERSION_NUMBER >= 0x30000000L
   int fips_mode= EVP_default_properties_is_fips_enabled(NULL) &&
@@ -3726,7 +3737,9 @@ static int init_ssl()
     FIPS_mode_set(0);
 #endif
   }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#endif
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
