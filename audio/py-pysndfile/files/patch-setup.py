--- setup.py.orig	2025-01-07 09:16:36 UTC
+++ setup.py
@@ -57,7 +57,7 @@ def find_libsndfile():
                     # only check for the mandatory main library, others are
                     # optional
                     found_lib = (tmp_lib_dir / "libsndfile.a").exists()
-                elif platform.system() == "Linux":
+                elif platform.system() == "Linux" or platform.system() == "FreeBSD":
                     found_lib = (tmp_lib_dir / "libsndfile.so").exists()
                 elif platform.system() == "Darwin":
                     found_lib = (tmp_lib_dir / "libsndfile.dylib").exists()
