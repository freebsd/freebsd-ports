--- src/mem/physical.cc.orig	2015-04-21 15:32:43 UTC
+++ src/mem/physical.cc
@@ -62,11 +62,9 @@
  * host. On OSX the MAP_NORESERVE flag does not exist, so simply make
  * it 0.
  */
-#if defined(__APPLE__)
 #ifndef MAP_NORESERVE
 #define MAP_NORESERVE 0
 #endif
-#endif
 
 using namespace std;
 
