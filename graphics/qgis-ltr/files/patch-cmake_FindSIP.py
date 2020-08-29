--- cmake/FindSIP.py.orig	2020-08-28 05:25:49 UTC
+++ cmake/FindSIP.py
@@ -30,17 +30,31 @@
 # Redistribution and use is allowed according to the terms of the BSD license.
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
-import sipconfig
+try:
+    import sipbuild
+except ImportError:  # Code for SIP v4
+    import sipconfig
 
-sipcfg = sipconfig.Configuration()
-print("sip_version:%06.0x" % sipcfg.sip_version)
-print("sip_version_num:%d" % sipcfg.sip_version)
-print("sip_version_str:%s" % sipcfg.sip_version_str)
-print("sip_bin:%s" % sipcfg.sip_bin)
-print("default_sip_dir:%s" % sipcfg.default_sip_dir)
-print("sip_inc_dir:%s" % sipcfg.sip_inc_dir)
-# SIP 4.19.10+ has new sipcfg.sip_module_dir
-if hasattr(sipcfg, "sip_module_dir"):
-    print("sip_module_dir:%s" % sipcfg.sip_module_dir)
-else:
-    print("sip_module_dir:%s" % sipcfg.sip_mod_dir)
+    sipcfg = sipconfig.Configuration()
+    print("sip_version:%06.0x" % sipcfg.sip_version)
+    print("sip_version_num:%d" % sipcfg.sip_version)
+    print("sip_version_str:%s" % sipcfg.sip_version_str)
+    print("sip_bin:%s" % sipcfg.sip_bin)
+    print("default_sip_dir:%s" % sipcfg.default_sip_dir)
+    print("sip_inc_dir:%s" % sipcfg.sip_inc_dir)
+    # SIP 4.19.10+ has new sipcfg.sip_module_dir
+    if hasattr(sipcfg, "sip_module_dir"):
+        print("sip_module_dir:%s" % sipcfg.sip_module_dir)
+    else:
+        print("sip_module_dir:%s" % sipcfg.sip_mod_dir)
+else:  # Code for SIP v5
+    print("sip_version:%06.0x" % sipbuild.version.SIP_VERSION)
+    print("sip_version_num:%d" % sipbuild.version.SIP_VERSION)
+    print("sip_version_str:%s" % sipbuild.version.SIP_VERSION_STR)
+
+    import shutil
+    print("sip_bin:%s" % shutil.which("sip5"))
+
+    from distutils.sysconfig import get_python_lib
+    python_modules_dir = "%%PYQT_SIPDIR%%"
+    print("default_sip_dir:%s" % python_modules_dir)
