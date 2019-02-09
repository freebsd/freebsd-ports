--- libshiboken/helper.h.orig	2018-12-17 07:28:47 UTC
+++ libshiboken/helper.h
@@ -90,7 +90,7 @@ class AutoArrayPointer
         T* data;
 };
 
-typedef unsigned long long ThreadId;
+typedef pthread_t ThreadId;
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
