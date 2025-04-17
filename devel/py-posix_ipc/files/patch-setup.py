--- setup.py.orig	2025-04-16 23:35:26 UTC
+++ setup.py
@@ -19,6 +19,7 @@ libraries = []
 DEPENDS = ["src/posix_ipc_module.c", "src/system_info.h"]
 
 libraries = []
+test_suite = "tests"
 
 system_info = build_support.discover_system_info.discover()
 
@@ -36,5 +37,6 @@ setuptools.setup(ext_modules=ext_modules,
                          )]
 
 setuptools.setup(ext_modules=ext_modules,
+                 test_suite=test_suite,
                  license=LICENSE,
                  )
