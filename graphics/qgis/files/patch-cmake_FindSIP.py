--- cmake/FindSIP.py.orig	2020-08-20 07:34:51 UTC
+++ cmake/FindSIP.py
@@ -56,5 +56,5 @@ else:  # Code for SIP v5
     print("sip_bin:%s" % shutil.which("sip5"))
 
     from distutils.sysconfig import get_python_lib
-    python_modules_dir = get_python_lib(plat_specific=1)
+    python_modules_dir = "%%PYQT_SIPDIR%%"
     print("default_sip_dir:%s" % python_modules_dir)
