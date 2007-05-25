--- ../../hotspot/src/os/bsd/vm/osThread_bsd.hpp.orig	Thu May 24 16:50:49 2007
+++ ../../hotspot/src/os/bsd/vm/osThread_bsd.hpp	Thu May 24 16:51:16 2007
@@ -28,7 +28,7 @@
 
 #ifndef PRODUCT
   // Used for debugging, return a unique integer for each thread.
-  int thread_identifier() const   { return (int)_thread_id; }
+  int thread_identifier() const   { return (int)(intptr_t)_thread_id; }
 #endif
 #ifdef ASSERT
   // On solaris reposition can fail in two ways:
