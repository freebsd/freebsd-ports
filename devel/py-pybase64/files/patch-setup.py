-- Link the bundled libbase64 static archive by full path instead of using
-- -lbase64, so the linker does not prefer the shared libbase64.so from
-- /usr/local/lib and leave internal table symbols unresolved.

--- setup.py.orig	2026-09-14 14:33:07 UTC
+++ setup.py
@@ -46,8 +46,7 @@ pybase64_ext = Extension(
         "src/pybase64/_pybase64_get_simd_flags.c",
     ],
     include_dirs=["base64/include/", "base64/lib/", ".base64_build"],
-    library_dirs=[".base64_build"],
-    libraries=["base64"],
+    extra_objects=[str(HERE / ".base64_build" / "libbase64.a")],
     define_macros=[("BASE64_STATIC_DEFINE", "1")],
     optional=OPTIONAL_EXTENSION,
 )
