--- port/stack_trace.cc.orig	2021-06-25 21:15:04 UTC
+++ port/stack_trace.cc
@@ -135,7 +135,7 @@ void PrintStack(int first_frames_to_skip) {
   void* frames[kMaxFrames];
 
   auto num_frames = backtrace(frames, kMaxFrames);
-  PrintStack(&frames[first_frames_to_skip], num_frames - first_frames_to_skip);
+  PrintStack(&frames[first_frames_to_skip], (int) (num_frames - first_frames_to_skip));
 }
 
 void PrintAndFreeStack(void* callstack, int num_frames) {
@@ -148,7 +148,7 @@ void* SaveStack(int* num_frames, int first_frames_to_s
   void* frames[kMaxFrames];
 
   auto count = backtrace(frames, kMaxFrames);
-  *num_frames = count - first_frames_to_skip;
+  *num_frames = (int) (count - first_frames_to_skip);
   void* callstack = malloc(sizeof(void*) * *num_frames);
   memcpy(callstack, &frames[first_frames_to_skip], sizeof(void*) * *num_frames);
   return callstack;
