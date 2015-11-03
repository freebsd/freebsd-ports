--- sope-mime/NGImap4/NGImap4Client.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4Client.m
@@ -77,12 +77,6 @@
 
 - (NSString *)_folder2ImapFolder:(NSString *)_folder;
 
-- (NGHashMap *)processCommand:(NSString *)_command;
-- (NGHashMap *)processCommand:(NSString *)_command withTag:(BOOL)_tag;
-- (NGHashMap *)processCommand:(NSString *)_command withTag:(BOOL)_tag
-  withNotification:(BOOL)_notification;
-- (NGHashMap *)processCommand:(NSString *)_command logText:(NSString *)_txt;
-
 - (void)sendCommand:(NSString *)_command;
 - (void)sendCommand:(NSString *)_command withTag:(BOOL)_tag;
 - (void)sendCommand:(NSString *)_command withTag:(BOOL)_tag
@@ -646,7 +640,7 @@ static NSMutableDictionary *namespaces;
 
   if (![self passwordIsSimple])
     s = [NSString stringWithFormat:@"login \"%@\" {%d}",
-		  self->login, plength];
+		  self->login, (int)plength];
   else
     s = [NSString stringWithFormat:@"login \"%@\" \"%@\"",
           self->login, self->password];
@@ -962,9 +956,9 @@ static NSMutableDictionary *namespaces;
 
   if (_folder == nil)
     return nil;
-  if ((_entry == nil))
+  if (_entry == nil)
     return nil;
-  if ((_attribute == nil))
+  if (_attribute == nil)
     return nil;
   if ((_folder = [self _folder2ImapFolder:_folder]) == nil)
     return nil;
@@ -994,11 +988,11 @@ static NSMutableDictionary *namespaces;
   
   if (_folder == nil)
     return nil;
-  if ((_entry == nil))
+  if (_entry == nil)
     return nil;
-  if ((_attribute == nil))
+  if (_attribute == nil)
     return nil;
-  if ((_value == nil))
+  if (_value == nil)
     return nil;
   if ((_folder = [self _folder2ImapFolder:_folder]) == nil)
     return nil;
@@ -1186,7 +1180,7 @@ static NSMutableDictionary *namespaces;
 
   cmd  = [NSString stringWithFormat:
                      @"UID FETCH %llu:%llu (UID) (CHANGEDSINCE 1)",
-                   _uid, _uid];
+                   (unsigned long long)_uid, (unsigned long long)_uid];
   fetchres = [self processCommand:cmd];
   result   = [self->normer normalizeFetchResponse:fetchres];
   return result;
@@ -1203,7 +1197,7 @@ static NSMutableDictionary *namespaces;
   
   cmd  = [NSString stringWithFormat:
                      @"UID FETCH 1:* (UID) (CHANGEDSINCE %llu VANISHED)",
-                   _modseq];
+                   (unsigned long long)_modseq];
   fetchres = [self processCommand:cmd];
   result   = [[self->normer normalizeFetchResponse:fetchres] retain];
   [pool release];
@@ -1329,7 +1323,7 @@ static NSMutableDictionary *namespaces;
   
   icmd = [NSString stringWithFormat:@"append \"%@\" (%@) {%d}",
                    _folder, [flags componentsJoinedByString:@" "],
-                   [rfc822Data length]];
+                   (int)[rfc822Data length]];
   result = [self processCommand:icmd
                  withTag:YES withNotification:NO];
   
