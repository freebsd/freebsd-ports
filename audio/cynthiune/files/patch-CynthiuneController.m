--- ./CynthiuneController.m.orig	2006-03-28 01:41:08.000000000 -0500
+++ ./CynthiuneController.m	2012-03-06 09:08:34.000000000 -0500
@@ -28,9 +28,6 @@
 #import <AppKit/NSPasteboard.h>
 #import <AppKit/NSToolbar.h>
 #import <AppKit/NSWindow.h>
-#ifdef GNUSTEP
-#import <AppKit/NSWindow+Toolbar.h>
-#endif
 #import <Foundation/NSArray.h>
 #import <Foundation/NSBundle.h>
 #import <Foundation/NSFileManager.h>
