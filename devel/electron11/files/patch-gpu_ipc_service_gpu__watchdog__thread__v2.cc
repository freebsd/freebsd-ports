--- gpu/ipc/service/gpu_watchdog_thread_v2.cc.orig	2021-03-20 14:36:05 UTC
+++ gpu/ipc/service/gpu_watchdog_thread_v2.cc
@@ -77,7 +77,7 @@ GpuWatchdogThreadImplV2::GpuWatchdogThreadImplV2(
   }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   tty_file_ = base::OpenFile(
       base::FilePath(FILE_PATH_LITERAL("/sys/class/tty/tty0/active")), "r");
   UpdateActiveTTY();
@@ -105,7 +105,7 @@ GpuWatchdogThreadImplV2::~GpuWatchdogThreadImplV2() {
     CloseHandle(watched_thread_handle_);
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
 #endif
@@ -481,7 +481,7 @@ void GpuWatchdogThreadImplV2::OnWatchdogTimeout() {
   if (foregrounded_event_)
     num_of_timeout_after_foregrounded_++;
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   UpdateActiveTTY();
 #endif
 
@@ -874,7 +874,7 @@ bool GpuWatchdogThreadImplV2::WithinOneMinFromForegrou
   return foregrounded_event_ && num_of_timeout_after_foregrounded_ <= count;
 }
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 void GpuWatchdogThreadImplV2::UpdateActiveTTY() {
   last_active_tty_ = active_tty_;
 
@@ -891,7 +891,7 @@ void GpuWatchdogThreadImplV2::UpdateActiveTTY() {
 #endif
 
 bool GpuWatchdogThreadImplV2::ContinueOnNonHostX11ServerTty() {
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (host_tty_ == -1 || active_tty_ == -1)
     return false;
 
