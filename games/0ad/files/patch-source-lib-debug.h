--- source/lib/debug.h.orig	2013-01-01 21:48:34.000000000 +0100
+++ source/lib/debug.h	2013-01-01 21:49:29.000000000 +0100
@@ -122,7 +122,7 @@
  * debugging the symbol engine.
  * use 0 as the initial value to avoid allocating .rdata space.
  **/
-const atomic_bool DEBUG_SUPPRESS = 0xAB;
+static const atomic_bool DEBUG_SUPPRESS = 0xAB;
 
 /**
  * choices offered by the error dialog that are returned
