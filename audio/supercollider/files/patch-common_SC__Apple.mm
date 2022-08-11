--- common/SC_Apple.mm.orig	2020-11-15 17:38:25 UTC
+++ common/SC_Apple.mm
@@ -42,65 +42,5 @@ void disableAppNap() {
     }
 }
 
-namespace EventLoop {
-
-static std::atomic_bool g_running;
-
-void setup() {
-    // The following code would transform the process into a foreground application.
-    // For now it's the plugin's responsibility to do this (early or lazily)
-    // because we don't want to always show an icon in the docker.
-    // ProcessSerialNumber psn = { 0, kCurrentProcess };
-    // TransformProcessType(&psn, kProcessTransformToForegroundApplication);
-
-    // Create NSApplication
-    [NSApplication sharedApplication];
-}
-
-void run() {
-#if 0
-    // this doesn't work...
-    [NSApp run];
-#else
-    // Kudos to https://www.cocoawithlove.com/2009/01/demystifying-nsapplication-by.html
-    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
-
-    [NSApp finishLaunching];
-    g_running = true;
-
-    while (g_running) {
-        [pool release];
-        pool = [[NSAutoreleasePool alloc] init];
-        NSEvent* event = [NSApp nextEventMatchingMask:NSAnyEventMask
-                                            untilDate:[NSDate distantFuture]
-                                               inMode:NSDefaultRunLoopMode
-                                              dequeue:YES];
-        if (event) {
-            [NSApp sendEvent:event];
-            [NSApp updateWindows];
-        }
-    }
-    [pool release];
-#endif
-}
-
-void quit() {
-    // break from event loop instead of [NSApp terminate:nil]
-    g_running = false;
-    // send dummy event to wake up event loop
-    NSEvent* event = [NSEvent otherEventWithType:NSApplicationDefined
-                                        location:NSMakePoint(0, 0)
-                                   modifierFlags:0
-                                       timestamp:0
-                                    windowNumber:0
-                                         context:nil
-                                         subtype:0
-                                           data1:0
-                                           data2:0];
-    [NSApp postEvent:event atStart:NO];
-}
-
-} // EventLoop
-
 } // namespace Apple
 } // namespace SC
