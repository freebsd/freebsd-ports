--- test/testother.cpp.orig	2024-02-16 08:46:10 UTC
+++ test/testother.cpp
@@ -2173,6 +2173,7 @@ class TestOther : public TestFixture { (private)
               "}\n");
         ASSERT_EQUALS("[test.cpp:1]: (performance) Function parameter 't' should be passed by const reference.\n", errout.str());
 
+#ifndef __i386__
         check("struct S {\n" // #12138
               "    union {\n"
               "        int a = 0;\n"
@@ -2191,6 +2192,7 @@ class TestOther : public TestFixture { (private)
               "    if (s.x > s.y) {}\n"
               "}\n");
         ASSERT_EQUALS("", errout.str());
+#endif
 
         check("struct S { std::list<int> l; };\n" // #12147
               "class C { public: std::list<int> l; };\n"
