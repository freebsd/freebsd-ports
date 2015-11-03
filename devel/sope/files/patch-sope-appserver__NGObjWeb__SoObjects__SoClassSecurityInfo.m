--- sope-appserver/NGObjWeb/SoObjects/SoClassSecurityInfo.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/SoObjects/SoClassSecurityInfo.m
@@ -111,7 +111,7 @@
   va_end(va);
 }
 
-- (void)declareProtected:(NSString *)_perm:(NSString *)_firstName, ... {
+- (void)declareProtected:(NSString *)_perm :(NSString *)_firstName, ... {
   va_list  va;
   NSString *aname;
 
