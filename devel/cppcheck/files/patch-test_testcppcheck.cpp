--- test/testcppcheck.cpp.orig	2026-06-20 16:49:32 UTC
+++ test/testcppcheck.cpp
@@ -597,7 +597,7 @@ class TestCppcheck : public TestFixture { (private)
 
     void purgedConfiguration() const
     {
-        ScopedFile test_file("test.cpp",
+        ScopedFile test_file("test_purged.cpp",
                              "#ifdef X\n"
                              "#endif\n"
                              "int main() {}\n");
@@ -618,7 +618,7 @@ class TestCppcheck : public TestFixture { (private)
         // the internal errorlist is cleared after each check() call
         ASSERT_EQUALS(1, errorLogger.errmsgs.size());
         auto it = errorLogger.errmsgs.cbegin();
-        ASSERT_EQUALS("test.cpp:0:0: information: The configuration 'X=X' was not checked because its code equals another one. [purgedConfiguration]",
+        ASSERT_EQUALS("test_purged.cpp:0:0: information: The configuration 'X=X' was not checked because its code equals another one. [purgedConfiguration]",
                       it->toString(false, templateFormat, ""));
     }
 
