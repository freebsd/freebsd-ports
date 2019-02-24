--- flow/ThreadPrimitives.h.orig	2019-01-09 22:28:32 UTC
+++ flow/ThreadPrimitives.h
@@ -25,7 +25,7 @@
 #include "Error.h"
 #include "Trace.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <semaphore.h>
 #endif
 
@@ -63,11 +63,11 @@ class ThreadSpinLock { (public)
 #endif
 	}
 	void leave() {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	__sync_synchronize();
 #endif
 		isLocked = 0;
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	__sync_synchronize();
 #endif
 #if VALGRIND
@@ -116,6 +116,8 @@ class Event { (private)
 #ifdef _WIN32
 	void* ev;
 #elif defined(__linux__)
+	sem_t sem;
+#elif defined(__FreeBSD__)
 	sem_t sem;
 #elif defined(__APPLE__)
 	mach_port_t self;
