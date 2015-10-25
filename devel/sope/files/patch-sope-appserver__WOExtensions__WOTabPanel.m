--- sope-appserver/WOExtensions/WOTabPanel.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WOExtensions/WOTabPanel.m
@@ -259,7 +259,7 @@
                      inComponent:sComponent];
   
   [_response appendContentString:@"</tr><tr><td colspan=\""];
-  s = [[NSString alloc] initWithFormat:@"%d",[ttabs count]];
+  s = [[NSString alloc] initWithFormat:@"%d",(int)[ttabs count]];
   [_response appendContentString:s];
   [s release];
   [_response appendContentString:@"\" bgcolor=\""];
