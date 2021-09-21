--- setup.py.orig	2021-09-07 21:17:59 UTC
+++ setup.py
@@ -70,7 +70,6 @@ def build_c_extension():
         packages=["google_crc32c"],
         package_dir={"": "src"},
         ext_modules=[module],
-        cmdclass={"build_ext": BuildExtWithDLL},
     )
 
 
