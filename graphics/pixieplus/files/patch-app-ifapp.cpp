--- app/ifapp.cpp.orig	Fri May 21 14:01:17 2004
+++ app/ifapp.cpp	Fri May 21 14:03:11 2004
@@ -34,7 +34,7 @@
 // ImageMagick message and progress stubs
 extern "C"{
     unsigned int magickMonitor(const char *msg, const off_t value,
-                               const size_t span, ExceptionInfo *)
+                               const long long unsigned int span, ExceptionInfo *)
     {
         if(!appPtr)
             return(true);
