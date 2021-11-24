--- remoting/host/chromoting_host_context.cc.orig	2021-07-15 19:13:43 UTC
+++ remoting/host/chromoting_host_context.cc
@@ -139,11 +139,11 @@ std::unique_ptr<ChromotingHostContext> ChromotingHostC
   // on a UI thread.
   scoped_refptr<AutoThreadTaskRunner> input_task_runner =
       AutoThread::CreateWithType("ChromotingInputThread", ui_task_runner,
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                  base::MessagePumpType::UI);
 #else
                                  base::MessagePumpType::IO);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   return base::WrapUnique(new ChromotingHostContext(
       ui_task_runner, audio_task_runner, file_task_runner, input_task_runner,
