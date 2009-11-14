--- Frameworks/ServicesBarKit/Source/SBServicesBar.m.orig	2006-07-30 19:58:37.000000000 +0200
+++ Frameworks/ServicesBarKit/Source/SBServicesBar.m	2009-05-16 14:13:19.000000000 +0200
@@ -27,7 +27,7 @@
 
 #import <Foundation/Foundation.h>
 #import <AppKit/AppKit.h>
-#import <GNUstepGUI/GSToolbar.h>
+#import <AppKit/NSToolbar.h>
 #import "SBServicesBarItem.h"
 #import "SBServicesBar.h"
 
@@ -55,7 +55,7 @@
 @interface SBServicesBar (ServicesBarKitPackage)
 + (SBServicesBar *) serverInstance;
 + (BOOL) setUpServerInstance: (SBServicesBar *)bar;
-- (GSToolbar *) toolbar;
+- (NSToolbar *) toolbar;
 @end
 
 
