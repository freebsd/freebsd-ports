--- setup.py.orig	2025-04-24 01:51:48 UTC
+++ setup.py
@@ -107,9 +107,6 @@ ext_modules = [
             "src/chacha8.c",
         ],
         include_dirs=[
-            # Path to pybind11 headers
-            get_pybind_include(),
-            get_pybind_include(user=True),
             "src",
             "uint128_t",
             ".",
@@ -186,6 +183,7 @@ if platform.system() == "Windows":
 if platform.system() == "Windows":
     setup(
         name="chiapos",
+	version="1.0.7",
         author="Mariano Sorgente",
         author_email="mariano@chia.net",
         description="Chia proof of space plotting, proving, and verifying (wraps C++)",
