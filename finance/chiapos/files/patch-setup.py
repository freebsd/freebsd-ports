--- setup.py.orig	2021-05-28 02:40:44 UTC
+++ setup.py
@@ -107,9 +100,6 @@ ext_modules = [
             "src/chacha8.c",
         ],
         include_dirs=[
-            # Path to pybind11 headers
-            get_pybind_include(),
-            get_pybind_include(user=True),
             "src",
             "uint128_t",
             ".",
@@ -202,6 +192,7 @@ if platform.system() == "Windows":
 else:
     setup(
         name="chiapos",
+        version="1.0.3",
         author="Mariano Sorgente",
         author_email="mariano@chia.net",
         description="Chia proof of space plotting, proving, and verifying (wraps C++)",
@@ -209,8 +200,7 @@ else:
         python_requires=">=3.7",
         long_description=open("README.md").read(),
         long_description_content_type="text/markdown",
-        url="https://github.com/Chia-Network/chiavdf",
-        ext_modules=[CMakeExtension("chiapos", ".")],
+        url="https://github.com/Chia-Network/chiapos",
         cmdclass=dict(build_ext=CMakeBuild),
         zip_safe=False,
     )
