--- ./ros/src/Standard/Standard_ErrorHandler.cxx.orig	Wed Mar 21 22:13:14 2007
+++ ./ros/src/Standard/Standard_ErrorHandler.cxx	Fri Mar 23 19:35:12 2007
@@ -33,7 +33,7 @@
 static inline Standard_Integer GetThreadID()
 {
 #ifndef WNT
-  return pthread_self();
+  return (Standard_Integer) pthread_self();
 #else
   return GetCurrentThreadId();
 #endif
