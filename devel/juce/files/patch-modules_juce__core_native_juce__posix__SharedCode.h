- workaround for work/JUCE-7.0.3/modules/juce_core/native/juce_posix_SharedCode.h

--- modules/juce_core/native/juce_posix_SharedCode.h.orig	2022-12-28 18:03:56 UTC
+++ modules/juce_core/native/juce_posix_SharedCode.h
@@ -928,7 +928,7 @@ class PosixSchedulerPriority (public)
 
         #if JUCE_MAC || JUCE_IOS
          const auto scheduler = SCHED_OTHER;
-        #elif JUCE_LINUX || JUCE_BSD
+        #elif JUCE_LINUX //|| JUCE_BSD
          const auto backgroundSched = prio == Thread::Priority::background ? SCHED_IDLE
                                                                            : SCHED_OTHER;
          const auto scheduler = isRealtime ? SCHED_RR : backgroundSched;
