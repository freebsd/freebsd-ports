--- sope-xml/SaxObjC/SaxObjectDecoder.m.orig	2015-09-16 18:26:50 UTC
+++ sope-xml/SaxObjC/SaxObjectDecoder.m
@@ -172,7 +172,7 @@ static NSNull *null = nil;
 		      reason:_ns
 		      userInfo:nil];
 }
-- (NSException *)missingElementMapping:(NSString *)_ns:(NSString *)_tag {
+- (NSException *)missingElementMapping:(NSString *)_ns :(NSString *)_tag {
   return [NSException exceptionWithName:@"MissingElementMapping"
 		      reason:_tag
 		      userInfo:nil];
