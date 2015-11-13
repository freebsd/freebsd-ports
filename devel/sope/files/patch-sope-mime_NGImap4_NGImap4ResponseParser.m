--- sope-mime/NGImap4/NGImap4ResponseParser.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4ResponseParser.m
@@ -1463,7 +1463,7 @@ _purifyQuotedString(NSMutableString *quo
   NSString            *name  = nil;
   NSString            *entry  = nil;
   NSMutableDictionary *attributes = nil;
-  NSDictionary *d, *f;
+  NSMutableDictionary *d, *f;
 
   if (!_matchesString(self, "ANNOTATION "))
     return NO;
@@ -1511,7 +1511,7 @@ _purifyQuotedString(NSMutableString *quo
     [attributes setObject:value
            forKey:[key lowercaseString]];
 
-    [d setObject:[NSDictionary dictionaryWithDictionary:attributes]
+    [d setObject:[NSMutableDictionary dictionaryWithDictionary:attributes]
        forKey:entry];
   }
   _consumeIfMatch(self, ')');
@@ -2484,7 +2484,7 @@ static BOOL _parseBadUntaggedResponse(NG
 static BOOL _parseNoOrOkArguments(NGImap4ResponseParser *self,
                                   NGMutableHashMap *result_, NSString *_key) 
 {
-  NSString *obj;
+  id obj;
 
   obj = nil;
   
