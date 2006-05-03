--- contrib/mod_ldap.c	Fri Apr 21 10:31:23 2006
+++ contrib/mod_ldap.c	Fri Apr 21 10:31:43 2006
@@ -55,7 +55,7 @@
  * after connecting to the LDAP server. If TLS cannot be enabled, the LDAP
  * connection will fail.
  */
-/* #define USE_LDAP_TLS */
+#define USE_LDAP_TLS
 
 /* Uncomment this if you have OpenSSL and wish to verify non-crypt()
  * password hashes locally with OpenSSL. You'll also need to edit--- contrib/mod_ldap.c	Fri Apr 21 10:31:23 2006
+++ contrib/mod_ldap.c	Fri Apr 21 10:31:43 2006
@@ -55,7 +55,7 @@
  * after connecting to the LDAP server. If TLS cannot be enabled, the LDAP
  * connection will fail.
  */
-/* #define USE_LDAP_TLS */
+#define USE_LDAP_TLS
 
 /* Uncomment this if you have OpenSSL and wish to verify non-crypt()
  * password hashes locally with OpenSSL. You'll also need to edit--- contrib/mod_ldap.c	Fri Apr 21 10:31:23 2006
+++ contrib/mod_ldap.c	Fri Apr 21 10:31:43 2006
@@ -55,7 +55,7 @@
  * after connecting to the LDAP server. If TLS cannot be enabled, the LDAP
  * connection will fail.
  */
-/* #define USE_LDAP_TLS */
+#define USE_LDAP_TLS
 
 /* Uncomment this if you have OpenSSL and wish to verify non-crypt()
  * password hashes locally with OpenSSL. You'll also need to edit
