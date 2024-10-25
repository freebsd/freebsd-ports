--- setup.py.orig	2024-10-21 22:20:04 UTC
+++ setup.py
@@ -12,7 +12,6 @@ import sysconfig
 import subprocess
 import sys
 import sysconfig
-from wheel.bdist_wheel import bdist_wheel
 if sys.platform == 'win32':
     # distutils is deprecated in Python 3.10 and removed in 3.12. However, it still works because Python defines a compatibility interface as long as setuptools is installed.
     # We don't have an official alternative for distutils.ccompiler as of September 2024. See: https://github.com/pypa/setuptools/issues/2806
@@ -306,20 +305,6 @@ class awscrt_build_ext(setuptools.command.build_ext.bu
         super().run()
 
 
-class bdist_wheel_abi3(bdist_wheel):
-    def get_tag(self):
-        python, abi, plat = super().get_tag()
-        # on CPython, our wheels are abi3 and compatible back to 3.11
-        if python.startswith("cp") and sys.version_info >= (3, 13):
-            # 3.13 deprecates PyWeakref_GetObject(), adds alternative
-            return "cp313", "abi3", plat
-        elif python.startswith("cp") and sys.version_info >= (3, 11):
-            # 3.11 is the first stable ABI that has everything we need
-            return "cp311", "abi3", plat
-
-        return python, abi, plat
-
-
 def awscrt_ext():
     # fetch the CFLAGS/LDFLAGS from env
     extra_compile_args = os.environ.get('CFLAGS', '').split()
@@ -468,6 +453,6 @@ setuptools.setup(
     ],
     python_requires='>=3.8',
     ext_modules=[awscrt_ext()],
-    cmdclass={'build_ext': awscrt_build_ext, "bdist_wheel": bdist_wheel_abi3},
+    cmdclass={'build_ext': awscrt_build_ext},
     test_suite='test',
 )
