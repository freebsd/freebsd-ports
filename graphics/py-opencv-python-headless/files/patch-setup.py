--- setup.py.orig	2025-07-04 16:37:46 UTC
+++ setup.py
@@ -23,8 +23,7 @@
     build_rolling = get_build_env_var_by_name("rolling")
 
     install_requires = [
-        'numpy<2.0; python_version<"3.9"',
-        'numpy>=2; python_version>="3.9"',
+        'numpy>=1.13.3',
     ]
 
     python_version = cmaker.CMaker.get_python_version()
@@ -186,6 +185,8 @@
             "-DBUILD_PERF_TESTS=OFF",
             "-DBUILD_DOCS=OFF",
             "-DPYTHON3_LIMITED_API=ON",
+            "-DWITH_PROTOBUF=OFF",
+            "-DWITH_VA=OFF",
             "-DBUILD_OPENEXR=ON",
         ]
         + (
