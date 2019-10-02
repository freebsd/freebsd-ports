--- libshiboken/helper.h.orig	2019-10-02 11:12:45 UTC
+++ libshiboken/helper.h
@@ -90,7 +90,7 @@ class AutoArrayPointer
         T *data;
 };
 
-using ThreadId = unsigned long long;
+using ThreadId = pthread_t;
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
