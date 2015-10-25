--- sope-appserver/NGObjWeb/SoObjects/SoClassSecurityInfo.h.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/SoObjects/SoClassSecurityInfo.h
@@ -101,7 +101,7 @@
 - (BOOL)hasDefaultAccessDeclaration;
 - (void)declarePublic:(NSString *)_firstName, ...;
 - (void)declarePrivate:(NSString *)_firstName, ...;
-- (void)declareProtected:(NSString *)_perm:(NSString *)_firstName, ...;
+- (void)declareProtected:(NSString *)_perm :(NSString *)_firstName, ...;
 
 /* object security */
 
