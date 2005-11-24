--- main.m.orig	Fri Oct 14 00:32:51 2005
+++ main.m	Wed Oct 19 14:08:21 2005
@@ -23,6 +23,11 @@
 	// pool.
 	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
 
+	NSString *gstepdir = [NSHomeDirectory() stringByAppendingPathComponent:@"GNUstep"];
+	NSString *libdir   = [gstepdir stringByAppendingPathComponent:@"Library"];
+	[[NSFileManager defaultManager] createDirectoryAtPath:gstepdir attributes:nil];
+	[[NSFileManager defaultManager] createDirectoryAtPath:libdir attributes:nil];
+
 	// dajt: allocate and set the NSApplication delegate manually because not
 	// using NIB to do this
 	controller = [[GameController alloc] init];
