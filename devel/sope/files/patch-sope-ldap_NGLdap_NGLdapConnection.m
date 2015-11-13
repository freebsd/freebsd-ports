--- sope-ldap/NGLdap/NGLdapConnection.m.orig	2015-09-16 18:26:50 UTC
+++ sope-ldap/NGLdap/NGLdapConnection.m
@@ -1223,7 +1223,7 @@ static void freeMods(LDAPMod **mods) {
   
   if ([self doesUseCache]) {
     [s appendFormat:@" cache[to=%.2fs,mem=%i]",
-         [self cacheTimeout], [self cacheMaxMemoryUsage]];
+         [self cacheTimeout], (int)[self cacheMaxMemoryUsage]];
   }
   
   [s appendString:@">"];
