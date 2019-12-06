--- sql/mysqld.cc.orig	2016-11-27 19:44:54 UTC
+++ sql/mysqld.cc
@@ -1517,6 +1517,16 @@ static void clean_up_mutexes()
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
@@ -3678,6 +3688,7 @@ static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
 #ifndef HAVE_YASSL
+#ifndef LIBRESSL_VERSION_NUMBER
   int fips_mode= FIPS_mode();
   if (fips_mode != 0)
   {
@@ -3687,7 +3698,9 @@ static int init_ssl()
         " Disabling FIPS.");
     FIPS_mode_set(0);
   }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#endif
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
