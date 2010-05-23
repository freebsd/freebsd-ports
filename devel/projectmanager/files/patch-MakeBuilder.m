--- ProjectModules/MakeBuilder/MakeBuilder.m.orig	2006-07-09 16:11:41.000000000 +0200
+++ ProjectModules/MakeBuilder/MakeBuilder.m	2010-05-23 06:03:12.000000000 +0200
@@ -23,13 +23,16 @@
 #import "MakeBuilder.h"
 
 #import <Foundation/NSArray.h>
+#import <Foundation/NSCharacterSet.h>
 #import <Foundation/NSException.h>
 #import <Foundation/NSFileHandle.h>
 #import <Foundation/NSNotification.h>
 #import <Foundation/NSString.h>
 #import <Foundation/NSTask.h>
 #import <Foundation/NSUserDefaults.h>
+#import <Foundation/NSValue.h>
 
+#import <AppKit/NSAttributedString.h>
 #import <AppKit/NSButton.h>
 #import <AppKit/NSCell.h>
 #import <AppKit/NSDocumentController.h>
@@ -46,7 +49,7 @@
 #import <AppKit/NSToolbar.h>
 #import <AppKit/NSToolbarItem.h>
 #import <AppKit/NSView.h>
-#import <AppKit/NSWindow+Toolbar.h>
+#import <AppKit/NSWindow.h>
 
 #import "MakeBuilderDelegate.h"
 #import "../../ProjectDocument.h"
