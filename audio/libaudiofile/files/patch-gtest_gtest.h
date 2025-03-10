--- gtest/gtest.h.orig	2013-02-11 17:23:26 UTC
+++ gtest/gtest.h
@@ -529,7 +529,7 @@
 // feature depending on tuple with be disabled in this mode).
 #ifndef GTEST_HAS_TR1_TUPLE
 // The user didn't tell us not to do it, so we assume it's OK.
-# define GTEST_HAS_TR1_TUPLE 1
+# define GTEST_HAS_TR1_TUPLE 0
 #endif  // GTEST_HAS_TR1_TUPLE
 
 // Determines whether Google Test's own tr1 tuple implementation
