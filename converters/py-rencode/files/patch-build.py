--- build.py.orig	2025-07-30 20:26:01 UTC
+++ build.py
@@ -11,7 +11,6 @@ from setuptools.command.build_ext import build_ext
 from setuptools.command.build_ext import build_ext
 
 
-COMPILE_ARGS = ["-march=native", "-O3", "-msse", "-msse2", "-mfma", "-mfpmath=sse"]
 LINK_ARGS: list[str] = []
 INCLUDE_DIRS: list[str] = []
 LIBRARIES: list[str] = []
@@ -22,7 +21,6 @@ def build() -> None:
         Extension(
             "*",
             ["rencode/*.pyx"],
-            extra_compile_args=COMPILE_ARGS,
             extra_link_args=LINK_ARGS,
             include_dirs=INCLUDE_DIRS,
             libraries=LIBRARIES,
