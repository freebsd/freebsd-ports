--- src/SDL/main.m.orig	Tue Jul 18 21:34:19 2006
+++ src/SDL/main.m	Thu Aug 17 11:03:44 2006
@@ -1,5 +1,3 @@
-#import <AppKit/NSApplication.h>
-
 #ifdef GNUSTEP
 #import <Foundation/NSAutoreleasePool.h>
 #import <Foundation/NSString.h>
@@ -25,6 +23,11 @@
 	// Need this because we're not using the default run loop's autorelease
 	// pool.
 	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
+
+	NSString *gstepdir = [NSHomeDirectory() stringByAppendingPathComponent:@"GNUstep"];
+	NSString *libdir   = [gstepdir stringByAppendingPathComponent:@"Library"];
+	[[NSFileManager defaultManager] createDirectoryAtPath:gstepdir attributes:nil];
+	[[NSFileManager defaultManager] createDirectoryAtPath:libdir attributes:nil];
 
 	// dajt: allocate and set the NSApplication delegate manually because not
 	// using NIB to do this
