--- common/SC_EventLoop.hpp.orig	2020-11-15 17:38:25 UTC
+++ common/SC_EventLoop.hpp
@@ -2,7 +2,7 @@
 
 #include <functional>
 #ifdef __APPLE__
-#    include "SC_Apple.hpp"
+#    include "SC_AppleEventLoop.hpp"
 #    include <thread>
 #endif
 
@@ -21,6 +21,7 @@ class EventLoop { (public)
         SC::Apple::EventLoop::setup();
 #endif
     }
+
     // Run the event loop until 'waitFunction' returns.
     static void run(std::function<void()> waitFunction) {
 #ifdef __APPLE__
