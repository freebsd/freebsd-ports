--- setup.py.orig	2021-11-15 10:00:19 UTC
+++ setup.py
@@ -37,7 +37,7 @@ setup(
     keywords="api graphql protocol api rest relay tartiflette dailymotion",
     packages=_PACKAGES,
     install_requires=[
-        "aiohttp>=3.5.4,<3.9.0",
+        "aiohttp>=3.5.4",
         "async_generator;python_version=='3.6.*'",
         "tartiflette>=0.12.0,<2.0.0",
     ],
