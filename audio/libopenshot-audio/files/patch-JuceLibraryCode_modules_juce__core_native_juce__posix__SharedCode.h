--- JuceLibraryCode/modules/juce_core/native/juce_posix_SharedCode.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_posix_SharedCode.h
@@ -148,7 +148,7 @@ void JUCE_CALLTYPE Process::terminate()
 }
 
 
-#if JUCE_MAC || JUCE_LINUX
+#if JUCE_BSD || JUCE_MAC || JUCE_LINUX
 bool Process::setMaxNumberOfFileHandles (int newMaxNumber) noexcept
 {
     rlimit lim;
@@ -987,6 +987,8 @@ void JUCE_CALLTYPE Thread::setCurrentThreadName (const
     {
         [[NSThread currentThread] setName: juceStringToNS (name)];
     }
+   #elif JUCE_BSD
+	pthread_set_name_np(pthread_self(), name.toRawUTF8());
    #elif JUCE_LINUX || JUCE_ANDROID
     #if ((JUCE_LINUX && (__GLIBC__ * 1000 + __GLIBC_MINOR__) >= 2012) \
           || JUCE_ANDROID && __ANDROID_API__ >= 9)
@@ -1040,14 +1042,20 @@ void JUCE_CALLTYPE Thread::yield()
 void JUCE_CALLTYPE Thread::setCurrentThreadAffinityMask (uint32 affinityMask)
 {
    #if SUPPORT_AFFINITIES
+     #if JUCE_BSD
+    cpuset_t affinity;
+     #else
     cpu_set_t affinity;
+     #endif
     CPU_ZERO (&affinity);
 
     for (int i = 0; i < 32; ++i)
         if ((affinityMask & (1 << i)) != 0)
             CPU_SET (i, &affinity);
 
-   #if (! JUCE_ANDROID) && ((! JUCE_LINUX) || ((__GLIBC__ * 1000 + __GLIBC_MINOR__) >= 2004))
+   #if JUCE_BSD
+    pthread_setaffinity_np (pthread_self(), sizeof (cpuset_t), &affinity);
+   #elif (! JUCE_ANDROID) && ((! JUCE_LINUX) || ((__GLIBC__ * 1000 + __GLIBC_MINOR__) >= 2004))
     pthread_setaffinity_np (pthread_self(), sizeof (cpu_set_t), &affinity);
    #elif JUCE_ANDROID
     sched_setaffinity (gettid(), sizeof (cpu_set_t), &affinity);
