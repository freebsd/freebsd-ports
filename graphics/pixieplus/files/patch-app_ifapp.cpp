--- app/ifapp.cpp.orig	Sat Sep 18 22:08:01 2004
+++ app/ifapp.cpp	Sat Sep 18 22:10:56 2004
@@ -33,18 +33,18 @@
 
 // ImageMagick message and progress stubs
 extern "C"{
-    unsigned int magickMonitor(const char *msg, const off_t value,
-                               const long long unsigned int span, ExceptionInfo *)
+    MagickBooleanType magickMonitor(const char *msg, const MagickOffsetType value,
+                               const MagickSizeType span, ExceptionInfo *)
     {
         if(!appPtr)
-            return(true);
+            return((MagickBooleanType)true);
         int val = (int)((((float)value)/((float)span))*100.0);
         if(appPtr->magickMessageProgress())
             appPtr->magickMessageProgress()->setValue(val);
         if(appPtr->magickMessageLabel())
             appPtr->magickMessageLabel()->setText(msg);
         appPtr->processEvents();
-        return(true);
+        return((MagickBooleanType)true);
     }
 
     void magickWarning(const ExceptionType /*warning*/, const char *reason,
