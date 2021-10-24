Workaround for https://github.com/pypa/setuptools_scm/issues/353

Original version (without the check for test sessions) obtained from:

https://github.com/OpenIndiana/oi-userland/commit/7d928fa26c0c5e4c29b4826fe78dc42401730529

--- src/setuptools_scm/file_finder_hg.py.orig	2021-10-20 09:29:52 UTC
+++ src/setuptools_scm/file_finder_hg.py
@@ -13,7 +13,12 @@ def _hg_toplevel(path):
                 universal_newlines=True,
                 stderr=devnull,
             )
-        return os.path.normcase(os.path.realpath(out.strip()))
+        toplevel_path = os.path.normcase(os.path.realpath(out.strip()))
+        setup_py_path = os.path.join(toplevel_path, "setup.py")
+        if os.path.exists(setup_py_path) or os.environ.get("_PYTEST_SESSION"):
+            return toplevel_path
+        else:
+            return None
     except subprocess.CalledProcessError:
         # hg returned error, we are not in a mercurial repo
         return None
