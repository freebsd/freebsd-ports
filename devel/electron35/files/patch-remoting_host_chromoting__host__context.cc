--- remoting/host/chromoting_host_context.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/host/chromoting_host_context.cc
@@ -292,7 +292,7 @@ std::unique_ptr<ChromotingHostContext> ChromotingHostC
   // on a UI thread.
   scoped_refptr<AutoThreadTaskRunner> input_task_runner =
       AutoThread::CreateWithType("ChromotingInputThread", ui_task_runner,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                  base::MessagePumpType::UI);
 #else
                                  base::MessagePumpType::IO);
