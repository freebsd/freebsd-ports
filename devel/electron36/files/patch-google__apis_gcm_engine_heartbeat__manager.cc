--- google_apis/gcm/engine/heartbeat_manager.cc.orig	2025-04-22 20:15:27 UTC
+++ google_apis/gcm/engine/heartbeat_manager.cc
@@ -31,7 +31,7 @@ const int kMinSuspendTimeMs = 1000 * 10; // 10 seconds
 // Minimum time spent sleeping before we force a new heartbeat.
 const int kMinSuspendTimeMs = 1000 * 10; // 10 seconds.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The period at which to check if the heartbeat time has passed. Used to
 // protect against platforms where the timer is delayed by the system being
 // suspended.  Only needed on linux because the other OSes provide a standard
@@ -190,7 +190,7 @@ void HeartbeatManager::RestartTimer() {
       base::BindRepeating(&HeartbeatManager::OnHeartbeatTriggered,
                           weak_ptr_factory_.GetWeakPtr()));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Windows, Mac, Android, iOS, and Chrome OS all provide a way to be notified
   // when the system is suspending or resuming.  The only one that does not is
   // Linux so we need to poll to check for missed heartbeats.
@@ -213,7 +213,7 @@ void HeartbeatManager::CheckForMissedHeartbeat() {
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Otherwise check again later.
   io_task_runner_->PostDelayedTask(
       FROM_HERE,
