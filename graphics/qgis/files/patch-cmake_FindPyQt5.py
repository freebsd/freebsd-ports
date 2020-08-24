--- cmake/FindPyQt5.py.orig	2020-08-20 07:52:34 UTC
+++ cmake/FindPyQt5.py
@@ -61,7 +61,7 @@ else:  # Code for SIP v5
     import shutil
     cfg = {
         'pyqt_mod_dir': os.path.dirname(PyQt5.__file__),
-        'pyqt_sip_dir': os.path.join(get_python_lib(plat_specific=1), "PyQt5", "bindings"),
+        'pyqt_sip_dir': "%%PYQT_SIPDIR%%",
         'pyqt_bin_dir': os.path.dirname(shutil.which("pyuic5")),
     }
 
