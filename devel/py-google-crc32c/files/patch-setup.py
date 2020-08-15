--- setup.py.orig	2020-03-21 00:48:10 UTC
+++ setup.py
@@ -54,7 +54,6 @@ def main(build_cffi=True):
     setuptools.setup(
         packages=["google_crc32c"],
         package_dir={"": "src"},
-        package_data={"google_crc32c": [os.path.join(_EXTRA_DLL, _DLL_FILENAME)]},
         setup_requires=[cffi_dep] if build_cffi else [],
         cffi_modules=[builder] if build_cffi else [],
         install_requires=[cffi_dep] if build_cffi else [],
