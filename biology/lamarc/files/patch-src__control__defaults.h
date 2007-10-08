--- src/control/defaults.h.orig	Sat Apr 28 04:56:55 2007
+++ src/control/defaults.h	Thu Aug 30 17:31:51 2007
@@ -243,7 +243,7 @@
   static const verbosity_type verbosity;
   static const verbosity_type progress;
 
-  static const long programstarttime;
+  static const time_t programstarttime;
   static const long randomseed;
 
   static const bool plotpost;
