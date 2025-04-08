--- remoting/protocol/webrtc_video_stream.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/protocol/webrtc_video_stream.cc
@@ -267,7 +267,7 @@ WebrtcVideoStream::WebrtcVideoStream(const SessionOpti
     : session_options_(session_options) {
 // TODO(joedow): Dig into the threading model on other platforms to see if they
 // can also be updated to run on a dedicated thread.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   core_task_runner_ = base::ThreadPool::CreateSingleThreadTaskRunner(
       {base::TaskPriority::HIGHEST},
       base::SingleThreadTaskRunnerThreadMode::DEDICATED);
