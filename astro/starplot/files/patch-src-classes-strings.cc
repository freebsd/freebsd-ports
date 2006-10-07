--- src/classes/strings.cc.orig	Tue Oct  3 18:28:35 2006
+++ src/classes/strings.cc	Tue Oct  3 18:28:44 2006
@@ -127,7 +127,7 @@
   // return the number of bytes that would have been written even if not
   // all of them are.  Hope this is true...
   va_start(args, format);
-  size_t size = std::vsnprintf(test, 2, format, args);
+  size_t size = vsnprintf(test, 2, format, args);
   va_end(args);
 
   // Write the result to a string
