--- sope-core/NGExtensions/FdExt.subproj/NGPropertyListParser.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/FdExt.subproj/NGPropertyListParser.m
@@ -453,7 +453,7 @@ static NSException *_makeException(NSExc
           }
         */
         if (!atEof && (_idx > 0)) {
-            register unsigned pos;
+            NSInteger pos;
             const unsigned char *startPos, *endPos;
 
             for (pos = _idx; (pos > 0) && (_buffer[pos] != '\n'); pos--)
