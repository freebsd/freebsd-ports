--- libshiboken/helper.h.orig	2026-08-14 07:58:27 UTC
+++ libshiboken/helper.h
@@ -74,7 +74,7 @@ using AutoArrayPointer = ArrayPointer<T>; // deprecate
 template <class T>
 using AutoArrayPointer = ArrayPointer<T>; // deprecated
 
-using ThreadId = unsigned long long;
+using ThreadId = pthread_t;
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
