Obtained from:  https://github.com/redis/redis-py/commit/fdfc0d2ff41687e7b77c794101114f47d9d5a560

--- setup.py.orig	2025-04-30 14:54:05 UTC
+++ setup.py
@@ -38,7 +38,7 @@ setup(
     python_requires=">=3.8",
     install_requires=[
         'async-timeout>=4.0.3; python_full_version<"3.11.3"',
-        "PyJWT~=2.9.0",
+        "PyJWT>=2.9.0",
     ],
     classifiers=[
         "Development Status :: 5 - Production/Stable",
