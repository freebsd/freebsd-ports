--- sope-ldap/NGLdap/NGLdapGlobalID.m.orig	2015-09-16 18:26:50 UTC
+++ sope-ldap/NGLdap/NGLdapGlobalID.m
@@ -53,7 +53,7 @@
 
 /* equality */
 
-- (unsigned)hash {
+- (NSUInteger)hash {
   return [self->dn hash] + [self->host hash];
 }
 
