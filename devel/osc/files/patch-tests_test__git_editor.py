--- tests/test_git_editor.py.orig	2026-05-27 14:39:15 UTC
+++ tests/test_git_editor.py
@@ -6,17 +6,21 @@ from osc.gitea_api.common import get_editor_command
 from osc.gitea_api.common import get_editor_command
 
 
+vim_executable = shutil.which("vim")
+nano_executable = shutil.which("nano")
+
+
 class TestGitEditor(unittest.TestCase):
 
     def test_default(self):
         with unittest.mock.patch.dict(os.environ, {"EDITOR": ""}):
             c = get_editor_command("test")
-        self.assertEqual(c, ["/usr/bin/vim", "test"])
+        self.assertEqual(c, [vim_executable, "test"])
 
     def test_custom(self):
         with unittest.mock.patch.dict(os.environ, {"EDITOR": "nano"}):
             c = get_editor_command("test")
-        self.assertEqual(c, ["/usr/bin/nano", "test"])
+        self.assertEqual(c, [nano_executable, "test"])
 
     def test_custom_with_param(self):
         with unittest.mock.patch.dict(os.environ, {"EDITOR": "/usr/bin/emacs -nv"}):
@@ -34,10 +38,10 @@ class TestGitEditor(unittest.TestCase):
         self.assertEqual(c, ["/usr/bin/mycmd", "-A", "my fancy  parameter ", "test"])
 
 
-if shutil.which("nano") != "/usr/bin/nano":
-    TestGitEditor = unittest.skip("nano is not /usr/bin/nano")(TestGitEditor)
-elif shutil.which("vim") != "/usr/bin/vim":
-    TestGitEditor = unittest.skip("vim is not /usr/bin/vim")(TestGitEditor)
+if nano_executable is None:
+    TestGitEditor = unittest.skip("nano executable missing")(TestGitEditor)
+elif vim_executable is None:
+    TestGitEditor = unittest.skip("vim executable missing")(TestGitEditor)
 
 if __name__ == "__main__":
     unittest.main()
