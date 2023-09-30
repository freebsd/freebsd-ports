--- setup.py.orig	2023-08-09 12:11:06 UTC
+++ setup.py
@@ -142,6 +142,5 @@ if getenv("READTHEDOCS", "False") == "True":
 else:
     setup(
         version=get_version(),
-        cmdclass={"build_ext": PillowHeifBuildExt},
         ext_modules=[Extension("_pillow_heif", ["pillow_heif/_pillow_heif.c"])],
     )
