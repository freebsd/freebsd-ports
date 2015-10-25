--- sope-mime/NGMail/NGMailAddressParser.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMail/NGMailAddressParser.m
@@ -349,15 +349,15 @@ static inline id parseDomainLiteral(NGMa
   uniString = [NSString stringWithCharacters:(unichar *)[_data bytes]
 			length:([_data length] / sizeof(unichar))];
 
-  return [(NGMailAddressParser *)self mailAddressParserWithString:uniString];
+  return [(id)self mailAddressParserWithString:uniString];
 }
 
-+ (id)mailAddressParserWithCString:(char *)_cString {
++ (id)mailAddressParserWithCString:(const char *)_cString {
   NSString *nsCString;
 
   nsCString = [NSString stringWithCString:_cString];
 
-  return [(NGMailAddressParser *)self mailAddressParserWithString:nsCString];
+  return [(id)self mailAddressParserWithString:nsCString];
 }
 
 + (id)mailAddressParserWithString:(NSString *)_string {
