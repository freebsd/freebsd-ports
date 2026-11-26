--- setup.py.orig	2026-01-01 00:00:00 UTC
+++ setup.py
@@ -18,7 +18,12 @@
 
 from setuptools import Extension, errors, setup
 from setuptools.command.build_ext import build_ext
-from setuptools.command.editable_wheel import editable_wheel
+try:
+    from setuptools.command.editable_wheel import editable_wheel
+except ImportError:
+    # setuptools < 64 has no editable_wheel command; editable installs are
+    # unsupported in that case, but regular wheel builds still work.
+    editable_wheel = object
 
 
 def get_version_data() -> dict[str, Any]:
@@ -177,9 +182,6 @@
         "console_scripts": [
             # Install a script as "coverage".
             "coverage = coverage.cmdline:main",
-            # And as "coverage3", and as "coverage-3.7" (or whatever), but deprecated.
-            f"coverage{py_major} = coverage.cmdline:main_deprecated",
-            f"coverage-{py_major}.{py_minor} = coverage.cmdline:main_deprecated",
         ],
     },
     extras_require={
@@ -190,7 +192,6 @@
     },
     cmdclass={
         "build_ext": ve_build_ext,
-        "editable_wheel": EditableWheelWithPth,
     },
     # We need to get HTML assets from our htmlfiles directory.
     zip_safe=False,
