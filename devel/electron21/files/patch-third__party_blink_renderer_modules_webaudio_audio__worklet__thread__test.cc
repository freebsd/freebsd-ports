--- third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2022-08-31 12:19:35 UTC
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -379,7 +379,7 @@ class AudioWorkletThreadPriorityTest
 
     // TODO(crbug.com/1022888): The worklet thread priority is always NORMAL
     // on OS_LINUX and OS_CHROMEOS regardless of the thread priority setting.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (expected_priority == base::ThreadPriorityForTest::kRealtimeAudio ||
         expected_priority == base::ThreadPriorityForTest::kDisplay) {
       EXPECT_EQ(actual_priority, base::ThreadPriorityForTest::kNormal);
