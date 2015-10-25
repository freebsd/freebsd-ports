--- sope-appserver/WEExtensions/WEResourceKey.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/WEResourceKey.m
@@ -65,7 +65,7 @@
 
 /* equality */
 
-- (unsigned)hash {
+- (NSUInteger)hash {
   if (self->hashValue == 0) {
     /* don't know whether this is smart, Nat! needs to comment ;-) */
     self->hashValue = [self->name hash];
