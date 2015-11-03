--- sope-appserver/NGObjWeb/Templates/WOHTMLParser.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/Templates/WOHTMLParser.m
@@ -246,7 +246,7 @@ static NSException *_makeHtmlException(N
       [ui setObject:self forKey:@"handler"];
     
     if (!atEof && (_idx > 0)) {
-      register unsigned pos;
+      NSInteger pos;
       const unichar *startPos, *endPos;
 
       for (pos = _idx; (pos >= 0) && (_buffer[pos] != '\n'); pos--)
