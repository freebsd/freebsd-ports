- Convert inline Python to 3.x syntax

--- tools/gn/exec_process_unittest.cc.orig	2019-05-30 00:15:11 UTC
+++ tools/gn/exec_process_unittest.cc
@@ -70,7 +70,7 @@ TEST(ExecProcessTest, TestLargeOutput) {
   std::string std_out, std_err;
   int exit_code;
 
-  ASSERT_TRUE(ExecPython("import sys; print 'o' * 1000000", &std_out, &std_err,
+  ASSERT_TRUE(ExecPython("import sys; print('o' * 1000000)", &std_out, &std_err,
                          &exit_code));
   EXPECT_EQ(0, exit_code);
   EXPECT_EQ(1000001u, std_out.size());
@@ -81,7 +81,7 @@ TEST(ExecProcessTest, TestStdoutAndStderrOutput) {
   int exit_code;
 
   ASSERT_TRUE(ExecPython(
-      "import sys; print 'o' * 10000; print >>sys.stderr, 'e' * 10000",
+      "from __future__ import print_function; import sys; print('o' * 10000); print('e' * 10000, file=sys.stderr)",
       &std_out, &std_err, &exit_code));
   EXPECT_EQ(0, exit_code);
   EXPECT_EQ(10001u, std_out.size());
@@ -90,7 +90,7 @@ TEST(ExecProcessTest, TestStdoutAndStderrOutput) {
   std_out.clear();
   std_err.clear();
   ASSERT_TRUE(ExecPython(
-      "import sys; print >>sys.stderr, 'e' * 10000; print 'o' * 10000",
+      "from __future__ import print_function; import sys; print('e' * 10000, file=sys.stderr); print('o' * 10000)",
       &std_out, &std_err, &exit_code));
   EXPECT_EQ(0, exit_code);
   EXPECT_EQ(10001u, std_out.size());
@@ -101,7 +101,7 @@ TEST(ExecProcessTest, TestOneOutputClosed) {
   std::string std_out, std_err;
   int exit_code;
 
-  ASSERT_TRUE(ExecPython("import sys; sys.stderr.close(); print 'o' * 10000",
+  ASSERT_TRUE(ExecPython("import sys; sys.stderr.close(); print('o' * 10000)",
                          &std_out, &std_err, &exit_code));
   EXPECT_EQ(0, exit_code);
   EXPECT_EQ(10001u, std_out.size());
@@ -110,7 +110,7 @@ TEST(ExecProcessTest, TestOneOutputClosed) {
   std_out.clear();
   std_err.clear();
   ASSERT_TRUE(ExecPython(
-      "import sys; sys.stdout.close(); print >>sys.stderr, 'e' * 10000",
+      "from __future__ import print_function; import sys; sys.stdout.close(); print('e' * 10000, file=sys.stderr)",
       &std_out, &std_err, &exit_code));
   EXPECT_EQ(0, exit_code);
   EXPECT_EQ(0u, std_out.size());
