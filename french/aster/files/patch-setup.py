--- setup.py.orig	2020-10-26 15:54:27 UTC
+++ setup.py
@@ -485,12 +485,12 @@ def main():
                                        [pythonXY, pythonXY + "m"],
                                        paths=[pylib], prefshared=True, err=True)
     cfg['PYTHON_LIBRARY'] = pylibrary
-    cfg['PYTHON_LIBRARY_DIR'] = osp.dirname(pylibrary)
-    pyinc = ftools.find_and_set(cfg, 'PYTHON_INCLUDE', "Python.h", typ='inc',
-                                paths=[osp.join(cfg['HOME_PYTHON'], 'include',
-                                                pythonXY)],
-                                err=True)
-    cfg['PYTHON_INCLUDE'] = osp.dirname(pyinc)
+    cfg['PYTHON_LIBRARY_DIR'] = osp.dirname(pylib)
+#    pyinc = ftools.find_and_set(cfg, 'PYTHON_INCLUDE', "Python.h", typ='inc',
+#                                paths=[osp.join(cfg['HOME_PYTHON'], 'include',
+#                                                pythonXY)],
+#                                err=True)
+#    cfg['PYTHON_INCLUDE'] = osp.dirname(pyinc)
     cfg['PYTHON_ALIAS'] = ''
     if PY3:
         py3tmpdir = tempfile.mkdtemp()
