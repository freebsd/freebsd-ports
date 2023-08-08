--- libshiboken/helper.h.orig	2020-12-13 07:16:46 UTC
+++ libshiboken/helper.h
@@ -92,7 +92,7 @@ class AutoArrayPointer
         T *data;
 };

-using ThreadId = unsigned long long;
+using ThreadId = pthread_t;
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();

