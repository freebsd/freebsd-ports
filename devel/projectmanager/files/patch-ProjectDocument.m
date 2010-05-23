--- ProjectDocument.m.orig	2006-07-09 16:11:43.000000000 +0200
+++ ProjectDocument.m	2010-05-23 06:04:25.000000000 +0200
@@ -25,9 +25,12 @@
 
 #import <Foundation/NSString.h>
 #import <Foundation/NSArray.h>
+#import <Foundation/NSCharacterSet.h>
 #import <Foundation/NSDictionary.h>
+#import <Foundation/NSDistributedNotificationCenter.h>
 #import <Foundation/NSUserDefaults.h>
 #import <Foundation/NSProcessInfo.h>
+#import <Foundation/NSError.h>
 
 #import <AppKit/NSWorkspace.h>
 #import <AppKit/NSDocumentController.h>
