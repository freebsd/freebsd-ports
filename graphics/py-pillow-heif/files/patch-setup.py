--- setup.py.orig	2023-12-02 13:40:59 UTC
+++ setup.py
@@ -269,7 +269,6 @@ try:
     else:
         setup(
             version=get_version(),
-            cmdclass={"build_ext": PillowHeifBuildExt},
             ext_modules=[Extension("_pillow_heif", ["pillow_heif/_pillow_heif.c"])],
             zip_safe=not PLATFORM_MINGW,
         )
