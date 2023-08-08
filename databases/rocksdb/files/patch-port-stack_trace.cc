--- port/stack_trace.cc.orig	2023-02-19 21:44:55 UTC
+++ port/stack_trace.cc
@@ -33,6 +33,8 @@ void* SaveStack(int* /*num_frames*/, int /*first_frame
 
 #ifdef OS_FREEBSD
 #include <sys/sysctl.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 #endif  // OS_FREEBSD
 #ifdef OS_LINUX
 #include <sys/prctl.h>
@@ -219,7 +221,7 @@ void PrintStack(int first_frames_to_skip) {
   void* frames[kMaxFrames];
 
   auto num_frames = backtrace(frames, kMaxFrames);
-  PrintStack(&frames[first_frames_to_skip], num_frames - first_frames_to_skip);
+  PrintStack(&frames[first_frames_to_skip], (int) (num_frames - first_frames_to_skip));
 }
 
 void PrintAndFreeStack(void* callstack, int num_frames) {
@@ -232,7 +234,7 @@ void* SaveStack(int* num_frames, int first_frames_to_s
   void* frames[kMaxFrames];
 
   auto count = backtrace(frames, kMaxFrames);
-  *num_frames = count - first_frames_to_skip;
+  *num_frames = (int) (count - first_frames_to_skip);
   void* callstack = malloc(sizeof(void*) * *num_frames);
   memcpy(callstack, &frames[first_frames_to_skip], sizeof(void*) * *num_frames);
   return callstack;
