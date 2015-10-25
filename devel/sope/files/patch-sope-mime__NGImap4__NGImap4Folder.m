--- sope-mime/NGImap4/NGImap4Folder.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4Folder.m
@@ -646,11 +646,11 @@ static int FetchNewUnseenMessagesInSubFo
       [m release];
     }
   }
-  m = [mes copy];
+  NSArray *a = [mes copy];
   [mes release]; mes = nil;
   [pool release];
   
-  return [m autorelease];;
+  return [a autorelease];;
 }
 
 - (NSArray *)_buildMessagesFromFetch:(NSDictionary *)_fetch {
