--- device/gamepad/gamepad_provider.cc.orig	2020-05-26 08:03:23 UTC
+++ device/gamepad/gamepad_provider.cc
@@ -147,7 +147,7 @@ void GamepadProvider::Initialize(std::unique_ptr<Gamep
 
   if (!polling_thread_)
     polling_thread_.reset(new base::Thread("Gamepad polling thread"));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;
