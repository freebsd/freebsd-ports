--- setup.py.orig	2026-02-12 14:20:47 UTC
+++ setup.py
@@ -115,22 +115,12 @@ else:
             Extension(
                 "librt.base64",
                 [
-                    "base64/librt_base64.c",
-                    "base64/lib.c",
-                    "base64/codec_choose.c",
-                    "base64/tables/tables.c",
-                    "base64/arch/generic/codec.c",
-                    "base64/arch/ssse3/codec.c",
-                    "base64/arch/sse41/codec.c",
-                    "base64/arch/sse42/codec.c",
-                    "base64/arch/avx/codec.c",
-                    "base64/arch/avx2/codec.c",
-                    "base64/arch/avx512/codec.c",
-                    "base64/arch/neon32/codec.c",
-                    "base64/arch/neon64/codec.c",
+                    "librt_base64.c",
                 ],
-                include_dirs=[".", "base64"],
+                include_dirs=[".", "%%LOCALBASE%%/include"],
                 extra_compile_args=cflags,
+                library_dirs = ["%%LOCALBASE%%/lib"],
+                libraries=["base64"],
             ),
             Extension(
                 "librt.vecs",
