--- ProjectWindowController.m.orig	2006-07-09 16:11:43.000000000 +0200
+++ ProjectWindowController.m	2010-05-23 05:56:35.000000000 +0200
@@ -25,7 +25,6 @@
 
 #import <AppKit/NSImage.h>
 #import <AppKit/NSWindow.h>
-#import <AppKit/NSWindow+Toolbar.h>
 #import <AppKit/NSToolbar.h>
 #import <AppKit/NSToolbarItem.h>
 #import <AppKit/NSBox.h>
@@ -35,8 +34,10 @@
 #import <AppKit/NSTextStorage.h>
 
 #import <Foundation/NSBundle.h>
+#import <Foundation/NSCalendarDate.h>
 #import <Foundation/NSException.h>
 #import <Foundation/NSNotification.h>
+#import <Foundation/NSUserDefaults.h>
 
 #import "ProjectDocument.h"
 #import "ProjectModule.h"
