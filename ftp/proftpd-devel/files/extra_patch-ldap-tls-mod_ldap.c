--- contrib/mod_ldap.c.orig	Thu Oct 19 18:18:07 2006
+++ contrib/mod_ldap.c	Fri Dec 15 11:01:21 2006
@@ -60,7 +60,7 @@
  * after connecting to the LDAP server. If TLS cannot be enabled, the LDAP
  * connection will fail.
  */
-/* #define USE_LDAP_TLS */
+#define USE_LDAP_TLS */
 
 /*
  * If you have to edit anything below this line, it's a bug. Report it
