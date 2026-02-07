--- test/test.py.orig	2023-03-17 17:34:51 UTC
+++ test/test.py
@@ -1247,11 +1247,11 @@ class TestBashGlobal(TestBash):
 
     def test_python_completion(self):
         self.sh.run_command("cd " + TEST_DIR)
-        self.assertEqual(self.sh.run_command("python3 ./prog basic f\t"), "foo\r\n")
+        self.assertEqual(self.sh.run_command("%%PYTHON_CMD%% ./prog basic f\t"), "foo\r\n")
 
     def test_python_filename_completion(self):
         self.sh.run_command("cd " + TEST_DIR)
-        self.assertEqual(self.sh.run_command("python3 ./pro\tbasic f\t"), "foo\r\n")
+        self.assertEqual(self.sh.run_command("%%PYTHON_CMD%% ./pro\tbasic f\t"), "foo\r\n")
 
     def test_python_not_executable(self):
         """Test completing a script that cannot be run directly."""
@@ -1263,7 +1263,7 @@ class TestBashGlobal(TestBash):
             # Ensure prog is no longer able to be run as "./prog".
             self.assertIn("<<126>>", self.sh.run_command('./prog; echo "<<$?>>"'))
             # Ensure completion still functions when run via python.
-            self.assertEqual(self.sh.run_command("python3 ./prog basic f\t"), "foo\r\n")
+            self.assertEqual(self.sh.run_command("%%PYTHON_CMD%% ./prog basic f\t"), "foo\r\n")
 
     def test_python_module(self):
         """Test completing a module run with python -m."""
@@ -1273,7 +1273,7 @@ class TestBashGlobal(TestBash):
             open("package/__init__.py", "w").close()
             shutil.copy(prog, "package/prog.py")
             self.sh.run_command("cd " + os.getcwd())
-            self.assertEqual(self.sh.run_command("python3 -m package.prog basic f\t"), "foo\r\n")
+            self.assertEqual(self.sh.run_command("%%PYTHON_CMD%% -m package.prog basic f\t"), "foo\r\n")
 
     def _test_console_script(self, package=False, wheel=False):
         with TempDir(prefix="test_dir_py", dir="."):
