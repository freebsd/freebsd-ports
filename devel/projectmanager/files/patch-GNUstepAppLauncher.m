--- ProjectModules/GNUstepAppLauncher/GNUstepAppLauncher.m.orig	2006-07-09 16:11:41.000000000 +0200
+++ ProjectModules/GNUstepAppLauncher/GNUstepAppLauncher.m	2010-05-23 05:53:40.000000000 +0200
@@ -30,6 +30,7 @@
 #import <Foundation/NSProcessInfo.h>
 #import <Foundation/NSString.h>
 #import <Foundation/NSTask.h>
+#import <Foundation/NSValue.h>
 
 #import <AppKit/NSColor.h>
 #import <AppKit/NSFont.h>
@@ -44,7 +45,7 @@
 #import <AppKit/NSTableView.h>
 #import <AppKit/NSTextStorage.h>
 #import <AppKit/NSTextView.h>
-#import <AppKit/NSWindow+Toolbar.h>
+#import <AppKit/NSWindow.h>
 #import <AppKit/NSToolbar.h>
 #import <AppKit/NSToolbarItem.h>
 
