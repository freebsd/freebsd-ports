--- setup.py.orig	2026-08-21 20:04:07 UTC
+++ setup.py
@@ -19,7 +19,12 @@ from setuptools.command.build_ext import build_ext
 
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
@@ -187,9 +192,6 @@ setup_args = dict(
         "console_scripts": [
             # Install a script as "coverage".
             "coverage = coverage.cmdline:main",
-            # And as "coverage3", and as "coverage-3.7" (or whatever), but deprecated.
-            "coverage%d = coverage.cmdline:main_deprecated" % sys.version_info[:1],
-            "coverage-%d.%d = coverage.cmdline:main_deprecated" % sys.version_info[:2],
         ],
     },
     extras_require={
@@ -198,7 +200,6 @@ setup_args = dict(
     },
     cmdclass={
         "build_ext": ve_build_ext,
-        "editable_wheel": EditableWheelWithPth,
     },
     # We need to get HTML assets from our htmlfiles directory.
     zip_safe=False,
