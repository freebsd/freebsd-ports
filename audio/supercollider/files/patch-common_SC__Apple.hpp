--- common/SC_Apple.hpp.orig	2020-11-15 17:38:25 UTC
+++ common/SC_Apple.hpp
@@ -23,19 +23,5 @@ namespace SC { namespace Apple {
 
 void disableAppNap();
 
-namespace EventLoop {
-
-// Setup the main application. This function must be called in the
-// main thread and before any other calls to Cocoa methods.
-void setup();
-// Run the event loop. This function must be called in the main thread.
-// It blocks until the event loop finishes.
-void run();
-// Ask the event loop to stop and terminate the program.
-// This function can be called from any thread.
-void quit();
-
-} // EventLoop
-
 } // namespace Apple
 } // namespace SC
