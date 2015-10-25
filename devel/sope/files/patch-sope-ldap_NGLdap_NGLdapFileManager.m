--- sope-ldap/NGLdap/NGLdapFileManager.m.orig	2015-09-16 18:26:50 UTC
+++ sope-ldap/NGLdap/NGLdapFileManager.m
@@ -317,7 +317,7 @@ static NSArray  *fileInfoAttrs    = nil;
   short count;
   
   if ((dn = [self dnForPath:_path]) == nil)
-    return NO;
+    return nil;
   
   entry = [self->connection entryAtDN:dn attributes:fileInfoAttrs];
   if (entry == nil)
@@ -432,7 +432,7 @@ static NSArray  *fileInfoAttrs    = nil;
   NGLdapEntry     *entry;
   
   if ((dn = [self dnForPath:_path]) == nil)
-    return NO;
+    return nil;
   
   entry = [self->connection entryAtDN:dn attributes:nil];
   if (entry == nil)
