--- app/ifapp.cpp	2004-05-22 10:02:26.000000000 -0400
+++ app/ifapp.cpp	2007-11-08 08:51:37.000000000 -0500
@@ -34,6 +34,7 @@
 // ImageMagick message and progress stubs
 extern "C"{
-    unsigned int magickMonitor(const char *msg, const off_t value,
-                               const long long unsigned int span, ExceptionInfo *)
+    static unsigned int
+    magickMonitor(const char *msg, const magick_int64_t value,
+                  const magick_uint64_t span, ExceptionInfo *)
     {
         if(!appPtr)
@@ -48,6 +49,7 @@
     }
 
-    void magickWarning(const ExceptionType /*warning*/, const char *reason,
-                       const char *description)
+    static void
+    magickWarning(const ExceptionType /*warning*/, const char *reason,
+                  const char *description)
     {
         QString str(reason);
@@ -58,6 +60,7 @@
     }
 
-    void magickError(const ExceptionType /*error*/, const char *reason,
-                     const char *description)
+    static void
+    magickError(const ExceptionType /*error*/, const char *reason,
+                const char *description)
     {
         QString str(reason);
@@ -68,6 +71,7 @@
     }
 
-    void magickFatalError(const ExceptionType /*error*/, const char *reason,
-                          const char *description)
+    static void
+    magickFatalError(const ExceptionType /*error*/, const char *reason,
+                     const char *description)
     {
         QString str(reason);
