--- sope-mime/NGImap4/NGImap4Functions.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4Functions.m
@@ -129,7 +129,7 @@ NGImap4Folder *_subFolderWithName
       if (debugFolderLookup) {
 	NSLog(@"  FAILED: %@", [[_parent context] lastException]);
       }
-      return NO;
+      return nil;
     }
   }
   if (debugFolderLookup) NSLog(@"  NOT FOUND.");
