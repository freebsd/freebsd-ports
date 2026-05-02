--- setup.py.orig	2025-03-06 05:53:30 UTC
+++ setup.py	2025-03-06 05:53:30 UTC
@@ -45,7 +45,7 @@ def _get_libsndfile_lib_name():
     elif os.environ.get("PYSNDFILE_USE_STATIC", "0") != "0":
         # only check for the mandatory main library, others are optional
         return "libsndfile.a"
-    elif platform.system() == "Linux":
+    elif platform.system() == "Linux" or platform.system() == "FreeBSD":
         return "libsndfile.so"
     elif platform.system() == "Darwin":
         return "libsndfile.dylib"
