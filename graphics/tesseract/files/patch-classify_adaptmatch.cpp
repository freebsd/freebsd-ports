--- classify/adaptmatch.cpp.orig	2009-09-11 06:08:28.000000000 -0400
+++ classify/adaptmatch.cpp	2009-09-11 06:10:13.000000000 -0400
@@ -444,6 +444,7 @@
     char empty_lengths[] = {0};
     if (!bln_numericmode)
       tprintf ("Nil classification!\n");  // Should never normally happen.
+    delete Results;
     return (append_choice (NIL, "", empty_lengths, 50.0f, -20.0f, -1));
   }
 
