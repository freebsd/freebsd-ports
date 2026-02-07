--- src/JuceLibraryCode/modules/juce_core/native/juce_posix_SharedCode.h.orig	2023-02-22 01:59:09 UTC
+++ src/JuceLibraryCode/modules/juce_core/native/juce_posix_SharedCode.h
@@ -963,7 +963,7 @@ void JUCE_CALLTYPE Thread::setCurrentThreadName (const
         [[NSThread currentThread] setName: juceStringToNS (name)];
     }
    #elif JUCE_LINUX
-    #if (__GLIBC__ * 1000 + __GLIBC_MINOR__) >= 2012
+    #if (__GLIBC__ * 1000 + __GLIBC_MINOR__) >= 2012 || defined(__FreeBSD__)
      pthread_setname_np (pthread_self(), name.toRawUTF8());
     #else
      prctl (PR_SET_NAME, name.toRawUTF8(), 0, 0, 0);
