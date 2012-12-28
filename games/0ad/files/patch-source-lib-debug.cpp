--- source/lib/debug.cpp.orig	2012-12-27 22:33:04.665325819 +0100
+++ source/lib/debug.cpp	2012-12-27 22:34:32.369332795 +0100
@@ -353,6 +353,8 @@
 // exit really doesn't want to see any more messages.
 static atomic_bool isExiting;
 
+const atomic_bool DEBUG_SUPPRESS = 0xAB;
+
 // this logic is applicable to any type of error. special cases such as
 // suppressing certain expected WARN_ERRs are done there.
 static bool ShouldSuppressError(atomic_bool* suppress)
