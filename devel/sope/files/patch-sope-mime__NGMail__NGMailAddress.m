--- sope-mime/NGMail/NGMailAddress.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMail/NGMailAddress.m
@@ -66,7 +66,7 @@
   return NO;
 }
 
-- (unsigned)hash {
+- (NSUInteger)hash {
   return [self->address hash];
 }
 
