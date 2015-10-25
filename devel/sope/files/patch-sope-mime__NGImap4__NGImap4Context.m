--- sope-mime/NGImap4/NGImap4Context.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4Context.m
@@ -944,8 +944,7 @@ static int ImapLogEnabled               
         [self serverName],
         [self serverKind],
         [self serverVersion],
-        [self serverSubVersion],
-        [self serverTag]];
+        [self serverSubVersion]];
   
   if (self->syncMode)
     [ms appendString:@" syncmode"];
