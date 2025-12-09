--- setup.py.orig	2025-12-05 21:07:15 UTC
+++ setup.py
@@ -172,21 +172,11 @@ else:
                 "librt.base64",
                 [
                     "librt_base64.c",
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
                 ],
-                include_dirs=[".", "base64"],
+                include_dirs=[".", "%%LOCALBASE%%/include"],
                 extra_compile_args=cflags,
+                library_dirs = ["%%LOCALBASE%%/lib"],
+                libraries=["base64"],
             ),
         ]
     )
