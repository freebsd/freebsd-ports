-- Fixes compatibility with newer setuptools/wheel versions:
-- 1. setuptools.command.bdist_wheel was removed; use wheel.bdist_wheel directly.
-- 2. Extension sources must be strings, not pathlib.Path objects.
-- This is necessary because setuptools.Extension no longer accepts
-- pathlib.Path objects in the sources list.

--- tools/setup_helpers/extension.py.orig	2026-10-31 08:24:04 UTC
+++ tools/setup_helpers/extension.py
@@ -2,7 +2,7 @@ from pathlib import Path
 import platform
 from pathlib import Path
 
-import setuptools.command.bdist_wheel
+from wheel.bdist_wheel import bdist_wheel as _bdist_wheel
 import torch
 from torch.utils.cpp_extension import BuildExtension, CppExtension, CUDAExtension
 
@@ -56,7 +56,7 @@ def get_build_ext():
     )
 
 
-class BdistWheelPy3None(setuptools.command.bdist_wheel.bdist_wheel):
+class BdistWheelPy3None(_bdist_wheel):
     """Tag the wheel py3-none so that a single wheel covers every CPython, including
     the free-threaded ones."""
 
@@ -116,8 +116,8 @@ def get_ext_modules():
         extension(
             name="torchaudio.lib._torchaudio",
             sources=[
-                _CSRC_DIR / "_torchaudio.cpp",
-                _CSRC_DIR / "utils.cpp",
+                str(_CSRC_DIR / "_torchaudio.cpp"),
+                str(_CSRC_DIR / "utils.cpp"),
             ],
             # Stops torch from linking libtorch_python, which is built per Python version.
             py_limited_api=True,
@@ -126,7 +126,7 @@ def get_ext_modules():
         ),
         extension(
             name="torchaudio.lib.libtorchaudio",
-            sources=[_CSRC_DIR / s for s in sources],
+            sources=[str(_CSRC_DIR / s) for s in sources],
             # Stops torch from linking libtorch_python, which is built per Python version.
             py_limited_api=True,
             extra_compile_args=extra_compile_args,
@@ -139,7 +139,7 @@ def get_ext_modules():
                 extension(
                     name="torchaudio.lib.torchaudio_prefixctc",
                     sources=[
-                        _CSRC_DIR / "cuctc" / "src" / s
+                        str(_CSRC_DIR / "cuctc" / "src" / s)
                         for s in ["ctc_prefix_decoder.cpp", "ctc_prefix_decoder_kernel_v2.cu", "python_binding.cpp"]
                     ],
                     # Stops torch from linking libtorch_python, which is built per Python version.
