--- sope-mime/NGImap4/NGImap4FileManager.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4FileManager.m
@@ -225,7 +225,7 @@ static BOOL debugOn = NO;
   if ((folder = [self _lookupFolderAtPathString:_path]) == nil)
     return NO;
 
-  ASSIGN(self->currentFolder, folder);
+  ASSIGN(self->currentFolder, (id)folder);
 
   return YES;
 }
