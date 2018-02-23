--- hotspot/src/share/vm/services/memTracker.cpp.orig
+++ hotspot/src/share/vm/services/memTracker.cpp
@@ -67,10 +67,6 @@ NMT_TrackingLevel MemTracker::init_tracking_level() {
     os::unsetenv(buf);
   }
 
-  // Construct NativeCallStack::EMPTY_STACK. It may get constructed twice,
-  // but it is benign, the results are the same.
-  ::new ((void*)&NativeCallStack::EMPTY_STACK) NativeCallStack(0, false);
-
   if (!MallocTracker::initialize(level) ||
       !VirtualMemoryTracker::initialize(level)) {
     level = NMT_off;
