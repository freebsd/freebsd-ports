--- third-party/gtest-1.8.1/fused-src/gtest/gtest-all.cc.orig	2020-05-27 23:38:10 UTC
+++ third-party/gtest-1.8.1/fused-src/gtest/gtest-all.cc
@@ -35,7 +35,7 @@
 
 // This line ensures that gtest.h can be compiled on its own, even
 // when it's fused.
-#include "gtest/gtest.h"
+#include "gtest.h"
 
 // The following lines pull in the real gtest *.cc files.
 // Copyright 2005, Google Inc.
