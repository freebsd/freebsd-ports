--- sope-mime/NGImap4/NGImap4Message.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4Message.m
@@ -243,8 +243,8 @@ static BOOL              ImapDebugEnable
 }
 
 - (void)markUnread {
-  if ([self isRead]);
-  [self removeFlag:@"seen"];
+  if ([self isRead])
+    [self removeFlag:@"seen"];
 }
 
 - (BOOL)isFlagged {
@@ -345,7 +345,7 @@ static BOOL              ImapDebugEnable
   return YES;
 }
 
-- (unsigned)hash {
+- (NSUInteger)hash {
   return self->uid;
 }
 
