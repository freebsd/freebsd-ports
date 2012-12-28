--- source/lib/debug.h.orig	2012-12-27 22:32:56.384331917 +0100
+++ source/lib/debug.h	2012-12-27 22:33:41.699327215 +0100
@@ -122,7 +122,7 @@
  * debugging the symbol engine.
  * use 0 as the initial value to avoid allocating .rdata space.
  **/
-const atomic_bool DEBUG_SUPPRESS = 0xAB;
+extern const atomic_bool DEBUG_SUPPRESS;
 
 /**
  * choices offered by the error dialog that are returned
