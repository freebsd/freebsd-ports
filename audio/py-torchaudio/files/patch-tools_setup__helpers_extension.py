-- Fixes compatibility with newer setuptools versions that require
-- extension sources to be strings instead of Path objects.
-- This is necessary because setuptools.Extension no longer accepts
-- pathlib.Path objects in the sources list.

--- tools/setup_helpers/extension.py.orig	2026-04-30 10:45:29 UTC
+++ tools/setup_helpers/extension.py
@@ -106,8 +106,8 @@ def get_ext_modules():
         extension(
             name="torchaudio.lib._torchaudio",
             sources=[
-                _CSRC_DIR / "_torchaudio.cpp",
-                _CSRC_DIR / "utils.cpp",
+                str(_CSRC_DIR / "_torchaudio.cpp"),
+                str(_CSRC_DIR / "utils.cpp"),
             ],
             py_limited_api=True,
             extra_compile_args=extra_compile_args,
@@ -115,7 +115,7 @@ def get_ext_modules():
         ),
         extension(
             name="torchaudio.lib.libtorchaudio",
-            sources=[_CSRC_DIR / s for s in sources],
+            sources=[str(_CSRC_DIR / s) for s in sources],
             py_limited_api=True,
             extra_compile_args=extra_compile_args,
             include_dirs=[_CSRC_DIR.parent],
@@ -127,7 +127,7 @@ def get_ext_modules():
                 extension(
                     name="torchaudio.lib.torchaudio_prefixctc",
                     sources=[
-                        _CSRC_DIR / "cuctc" / "src" / s
+                        str(_CSRC_DIR / "cuctc" / "src" / s)
                         for s in ["ctc_prefix_decoder.cpp", "ctc_prefix_decoder_kernel_v2.cu", "python_binding.cpp"]
                     ],
                     py_limited_api=True,
