--- Frameworks/ServicesBarKit/ServicesBarMenulet/ServicesBarMenulet.m.orig	2006-06-04 13:17:39.000000000 +0200
+++ Frameworks/ServicesBarKit/ServicesBarMenulet/ServicesBarMenulet.m	2009-05-16 14:20:38.000000000 +0200
@@ -32,14 +32,14 @@
 
 @interface SBServicesBar (ServicesBarKitPackage)
 + (BOOL) setUpServerInstance: (id)instance;
-- (GSToolbar *) toolbar;
+- (NSToolbar *) toolbar;
 @end
 
 @interface ServicesBarMenulet (ServicesBarKitPrivate)
 -(BOOL) publishServicesBarInstance;
 @end
 
-@interface GSToolbar (Private)
+@interface NSToolbar (Private)
 - (NSView *) _backView;
 - (GSToolbarView *) _toolbarView;
 @end
