--- gruel/src/lib/thread.cc.orig	2013-05-01 18:57:50.000000000 -0500
+++ gruel/src/lib/thread.cc	2013-05-30 06:43:24.000000000 -0500
@@ -95,7 +95,7 @@
   }
 } /* namespace gruel */
 
-#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
+#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 
 namespace gruel {
 
