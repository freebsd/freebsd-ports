--- sope-mime/NGImap4/NGImap4FolderGlobalID.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4FolderGlobalID.m
@@ -62,7 +62,7 @@
 
 /* comparison */
 
-- (unsigned)hash {
+- (NSUInteger)hash {
   return [self->absoluteName hash];
 }
 
