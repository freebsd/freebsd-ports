--- setup.py.orig	2023-11-22 00:46:47 UTC
+++ setup.py
@@ -14,7 +14,6 @@ import shutil
 import subprocess
 import sys
 import sysconfig
-from wheel.bdist_wheel import bdist_wheel
 
 
 def is_64bit():
@@ -283,16 +282,6 @@ class awscrt_build_ext(setuptools.command.build_ext.bu
         super().run()
 
 
-class bdist_wheel_abi3(bdist_wheel):
-    def get_tag(self):
-        python, abi, plat = super().get_tag()
-        if python.startswith("cp") and sys.version_info >= (3, 11):
-            # on CPython, our wheels are abi3 and compatible back to 3.11
-            return "cp311", "abi3", plat
-
-        return python, abi, plat
-
-
 def awscrt_ext():
     # fetch the CFLAGS/LDFLAGS from env
     extra_compile_args = os.environ.get('CFLAGS', '').split()
@@ -415,6 +404,6 @@ setuptools.setup(
     ],
     python_requires='>=3.7',
     ext_modules=[awscrt_ext()],
-    cmdclass={'build_ext': awscrt_build_ext, "bdist_wheel": bdist_wheel_abi3},
+    cmdclass={'build_ext': awscrt_build_ext},
     test_suite='test',
 )
