--- lib/ldap.c.orig	Thu Jun  6 17:14:16 2002
+++ lib/ldap.c	Thu Jun  6 17:14:24 2002
@@ -147,7 +147,7 @@
   int ldaptext;
   struct SessionHandle *data=conn->data;
   
-  infof(data, "LDAP: %s %s\n", data->change.url);
+  infof(data, "LDAP: %s\n", data->change.url);
 
   DynaOpen();
   if (libldap == NULL) {
