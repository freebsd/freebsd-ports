--- setup.py.orig	2019-10-01 12:45:34 UTC
+++ setup.py
@@ -419,8 +419,8 @@ def main():
     # librairies
     pylib = SC.get_python_lib(standard_lib=True)
     prefixlib = osp.dirname(pylib)
-    cfg['PYTHONLIB']  = '-L' + prefixlib + ' -L' + osp.join(pylib, 'config') + \
-        ' -l' + pythonXY
+    cfg['PYTHONLIB']  = '-L' + prefixlib + ' -L' + pylib + \
+        ' -l' + pythonXY + '%%PYTHON_ABIVER%%'
     # python modules location
     cfg['PYTHONPATH'] = cfg.get('PYTHONPATH', '')
     cfg['OPT_ENV'] = cfg.get('OPT_ENV', '')
@@ -488,14 +488,14 @@ def main():
     ftools.find_and_set(
         cfg, 'SHELL_EXECUTION', ['bash', 'ksh', 'zsh'], err=False)
     ftools.check(python_version, 'Python version')
-    pylibrary = ftools.findlib_and_set(cfg, 'PYTHON_LIBRARY', pythonXY,
+    pylibrary = ftools.findlib_and_set(cfg, 'PYTHON_LIBRARY', pythonXY + 'm',
                                        paths=[pylib], prefshared=True, err=True)
     cfg['PYTHON_LIBRARY'] = pylibrary
-    pyinc = ftools.find_and_set(cfg, 'PYTHON_INCLUDE', "Python.h", typ='inc',
-                                paths=[osp.join(cfg['HOME_PYTHON'], 'include',
-                                                pythonXY)],
-                                err=True)
-    cfg['PYTHON_INCLUDE'] = osp.dirname(pyinc)
+    #pyinc = ftools.find_and_set(cfg, 'PYTHON_INCLUDE', "Python.h", typ='inc',
+    #                            paths=[osp.join(cfg['HOME_PYTHON'], 'include',
+    #                                            pythonXY + '%%PYTHON_ABIVER%%')],
+    #                            append=False, err=True)
+    #cfg['PYTHON_INCLUDE'] = osp.dirname(pyinc)
     cfg['PYTHON_ALIAS'] = ''
     if PY3:
         py3tmpdir = tempfile.mkdtemp()
