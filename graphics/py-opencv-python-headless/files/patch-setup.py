-- Relax numpy pin so the port builds with the numpy version in ports,
-- and disable Intel IPP (IPPICV) because it ships Linux-only prebuilt
-- binaries that cannot be used on FreeBSD.  Also turn off protobuf and
-- video acceleration backends that are not needed for this package.

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
@@ -183,6 +182,9 @@
             "-DBUILD_PERF_TESTS=OFF",
             "-DBUILD_DOCS=OFF",
             "-DPYTHON3_LIMITED_API=ON",
+            "-DWITH_IPP=OFF",
+            "-DWITH_PROTOBUF=OFF",
+            "-DWITH_VA=OFF",
             "-DBUILD_OPENEXR=ON",
         ]
         + (
