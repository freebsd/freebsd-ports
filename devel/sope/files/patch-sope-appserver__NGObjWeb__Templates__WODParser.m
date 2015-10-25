--- sope-appserver/NGObjWeb/Templates/WODParser.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/Templates/WODParser.m
@@ -271,7 +271,7 @@ static NSException *_makeException(NSExc
   [ui setObject:[NumberClass numberWithInt:_idx]     forKey:@"position"];
 
   if (!atEof && (_idx > 0)) {
-    register unsigned pos;
+    NSInteger pos;
     const unichar *startPos, *endPos;
 
     for (pos = _idx; (pos >= 0) && (_buffer[pos] != '\n'); pos--)
