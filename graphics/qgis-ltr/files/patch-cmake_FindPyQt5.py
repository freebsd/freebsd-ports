--- cmake/FindPyQt5.py.orig	2020-08-28 05:25:49 UTC
+++ cmake/FindPyQt5.py
@@ -30,14 +30,15 @@
 # Redistribution and use is allowed according to the terms of the BSD license.
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
+import os.path
+import PyQt5.QtCore
+
 try:
-    import PyQt5.pyqtconfig
-    pyqtcfg = PyQt5.pyqtconfig.Configuration()
+    __import__('sipbuild')
 except ImportError:
-    import PyQt5.QtCore
-    import sipconfig # won't work for SIP v5
-    import os.path
+    import sipconfig  # won't work for SIP v5
     import sys
+
     cfg = sipconfig.Configuration()
     sip_dir = cfg.default_sip_dir
     if sys.platform.startswith('freebsd'):
@@ -51,38 +52,44 @@ except ImportError:
             sip_dir = p
             break
     cfg = {
-        'pyqt_version': PyQt5.QtCore.PYQT_VERSION,
-        'pyqt_version_str': PyQt5.QtCore.PYQT_VERSION_STR,
-        'pyqt_sip_flags': PyQt5.QtCore.PYQT_CONFIGURATION['sip_flags'],
         'pyqt_mod_dir': os.path.join(cfg.default_mod_dir, "PyQt5"),
         'pyqt_sip_dir': sip_dir,
         'pyqt_bin_dir': cfg.default_bin_dir,
     }
-    pyqtcfg = sipconfig.Configuration([cfg])
+else:  # Code for SIP v5
+    from distutils.sysconfig import get_python_lib
+    import shutil
+    cfg = {
+        'pyqt_mod_dir': os.path.dirname(PyQt5.__file__),
+        'pyqt_sip_dir': "%%PYQT_SIPDIR%%",
+        'pyqt_bin_dir': os.path.dirname(shutil.which("pyuic5")),
+    }
 
-print("pyqt_version:%06.0x" % pyqtcfg.pyqt_version)
-print("pyqt_version_num:%d" % pyqtcfg.pyqt_version)
-print("pyqt_version_str:%s" % pyqtcfg.pyqt_version_str)
+print("pyqt_version:%06.0x" % PyQt5.QtCore.PYQT_VERSION)
+print("pyqt_version_num:%d" % PyQt5.QtCore.PYQT_VERSION)
+print("pyqt_version_str:%s" % PyQt5.QtCore.PYQT_VERSION_STR)
 
 pyqt_version_tag = ""
 in_t = False
-for item in pyqtcfg.pyqt_sip_flags.split(' '):
+pyqt_config_list = PyQt5.QtCore.PYQT_CONFIGURATION["sip_flags"].split(' ')
+for item in pyqt_config_list:
     if item == "-t":
         in_t = True
     elif in_t:
-        if item.startswith("Qt_4"):
+        if item.startswith("Qt_5"):
             pyqt_version_tag = item
     else:
         in_t = False
 print("pyqt_version_tag:%s" % pyqt_version_tag)
 
-print("pyqt_mod_dir:%s" % pyqtcfg.pyqt_mod_dir)
-print("pyqt_sip_dir:%s" % pyqtcfg.pyqt_sip_dir)
-print("pyqt_sip_flags:%s" % pyqtcfg.pyqt_sip_flags)
-print("pyqt_bin_dir:%s" % pyqtcfg.pyqt_bin_dir)
+print("pyqt_mod_dir:%s" % cfg['pyqt_mod_dir'])
+print("pyqt_sip_dir:%s" % cfg['pyqt_sip_dir'])
+print("pyqt_sip_flags:%s" % PyQt5.QtCore.PYQT_CONFIGURATION['sip_flags'])
+print("pyqt_bin_dir:%s" % cfg['pyqt_bin_dir'])
 
 try:
     import PyQt5.sip
+
     print("pyqt_sip_module:PyQt5.sip")
 except:
     print("pyqt_sip_module:sip")
