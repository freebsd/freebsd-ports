--- samples/sample_binary.cpp.orig	2016-08-16 00:29:35 UTC
+++ samples/sample_binary.cpp
@@ -15,6 +15,7 @@
  */
 
 #include "monster_generated.h" // Already includes "flatbuffers/flatbuffers.h".
+#include <cstdio>
 
 using namespace MyGame::Sample;
 
