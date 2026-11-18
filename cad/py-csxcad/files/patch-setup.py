--- setup.py.orig	2026-10-09 15:41:16 UTC
+++ setup.py
@@ -222,7 +222,6 @@ setup(
   ),
   packages=["CSXCAD", ],
   package_data={'CSXCAD': ['*.pxd']},
-  # DO NOT add any new build-time dependency in setup_requires.
   # We should use pyproject.toml exclusively. The only item
   # "cython" is meant to activate auto-Cython feature in
   # setuptools 18.
