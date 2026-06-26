--- setup.py.orig	2023-02-23 12:56:33 UTC
+++ setup.py
@@ -16,7 +16,7 @@ setup_args = dict(
     python_requires=">=3.7",
     setup_requires=["setuptools>=40.0"],
     license="BSD-3-Clause",
-    packages=find_packages(),
+    packages=find_packages(exclude = ["tests", "tests.*"]),
     author="Petr Gargulak",
     author_email="petr.gargulak@nxp.com",
     keywords=["PEMicro", "PyPEMicro"],
