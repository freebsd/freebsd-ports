Workaround for https://github.com/pypa/setuptools_scm/issues/353

Original version (without the check for test sessions) obtained from:

https://github.com/OpenIndiana/oi-userland/commit/7d928fa26c0c5e4c29b4826fe78dc42401730529

--- src/setuptools_scm/file_finder_git.py.orig	2021-10-20 09:27:26 UTC
+++ src/setuptools_scm/file_finder_git.py
@@ -18,7 +18,12 @@ def _git_toplevel(path):
                 stderr=devnull,
             )
         trace("find files toplevel", out)
-        return os.path.normcase(os.path.realpath(out.strip()))
+        toplevel_path = os.path.normcase(os.path.realpath(out.strip()))
+        setup_py_path = os.path.join(toplevel_path, "setup.py")
+        if os.path.exists(setup_py_path) or os.environ.get("_PYTEST_SESSION"):
+            return toplevel_path
+        else:
+            return None
     except subprocess.CalledProcessError:
         # git returned error, we are not in a git repo
         return None
