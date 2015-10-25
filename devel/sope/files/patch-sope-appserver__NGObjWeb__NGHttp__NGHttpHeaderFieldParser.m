--- sope-appserver/NGObjWeb/NGHttp/NGHttpHeaderFieldParser.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/NGHttp/NGHttpHeaderFieldParser.m
@@ -31,7 +31,7 @@ static Class NSArrayClass = Nil;
 - (id)parseValue:(id)_data ofHeaderField:(NSString *)_field {
   unsigned              len   = 0;
   const unsigned char   *src  = NULL;
-  NGHttpHostHeaderField *value = nil;
+  id                     value = nil;
   NSString *str = nil;
 
   if ([_data isKindOfClass:[NSData class]]) {
