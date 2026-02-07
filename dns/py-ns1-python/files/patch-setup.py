--- setup.py.orig	2024-12-13 10:23:24 UTC
+++ setup.py
@@ -23,8 +23,6 @@ setup(
     url="https://github.com/ns1/ns1-python",
     packages=find_packages(exclude=["tests", "examples"]),
     setup_requires=[
-        "pytest-runner",
-        "wheel",
     ],
     tests_require=[
         "pytest",
