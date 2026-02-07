--- libshiboken/helper.h.orig	2023-10-14 09:37:51 UTC
+++ libshiboken/helper.h
@@ -61,7 +61,7 @@ class AutoArrayPointer
         T *data;
 };
 
-using ThreadId = unsigned long long;
+using ThreadId = pthread_t;
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
