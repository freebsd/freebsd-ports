This test requires /proc to be mounted

--- test/testpath.cpp.orig	2023-06-22 09:07:56 UTC
+++ test/testpath.cpp
@@ -74,7 +74,9 @@ class TestPath : public TestFixture { (private)
     }
 
     void getCurrentExecutablePath() const {
+#ifndef __FreeBSD__
         ASSERT_EQUALS(false, Path::getCurrentExecutablePath("").empty());
+#endif
     }
 
     void isAbsolute() const {
