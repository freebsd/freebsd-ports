--- sql/mysqld.cc.orig	2018-05-06 19:15:48 UTC
+++ sql/mysqld.cc
@@ -4321,7 +4321,7 @@ static void init_ssl() {
 
 static void init_ssl() {
 #ifdef HAVE_OPENSSL
-#if !defined(HAVE_WOLFSSL) && !defined(__sun)
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER) && !defined(__sun)
 #if defined(HAVE_PSI_MEMORY_INTERFACE)
   static PSI_memory_info all_openssl_memory[] = {
       {&key_memory_openssl, "openssl_malloc", 0, 0,
