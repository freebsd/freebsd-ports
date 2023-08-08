--- tests/test_pytoolconfig.py.orig	2022-06-28 03:43:15 UTC
+++ tests/test_pytoolconfig.py
@@ -80,7 +80,7 @@ def test_global(cwd):
 
 
 def test_global(cwd):
-    if sys.platform != "linux":
+    if not (sys.platform.startswith("linux") | sys.platform.startswith("freebsd")):
         pytest.skip()
     os.environ["XDG_CONFIG_HOME"] = cwd.as_posix()
     config = PyToolConfig("bogus", cwd, NestedModel, global_config=True)
