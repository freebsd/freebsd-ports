--- ./src/modules/extra/m_ldapauth.cpp.orig	2008-03-15 13:33:33.000000000 +0000
+++ ./src/modules/extra/m_ldapauth.cpp	2008-04-11 13:34:37.000000000 +0100
@@ -29,7 +29,7 @@
 #include <ldap.h>
 
 /* $ModDesc: Allow/Deny connections based upon answer from LDAP server */
-/* $LinkerFlags: -lldap */
+/* $LinkerFlags: -L/usr/local/lib -lldap */
 
 class ModuleLDAPAuth : public Module
 {
