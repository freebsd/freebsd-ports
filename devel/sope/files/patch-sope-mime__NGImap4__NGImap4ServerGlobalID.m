--- sope-mime/NGImap4/NGImap4ServerGlobalID.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4ServerGlobalID.m
@@ -65,7 +65,7 @@
 
 /* comparison */
 
-- (unsigned)hash {
+- (NSUInteger)hash {
   return [self->login hash];
 }
 
