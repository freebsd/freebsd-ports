--- setup.py.orig	2022-03-12 07:31:32 UTC
+++ setup.py
@@ -24,7 +24,7 @@ setup(
         # TODO: do we need to name the LHS 'pytest_relaxed' too? meh
         "pytest11": ["relaxed = pytest_relaxed.plugin"]
     },
-    install_requires=["pytest>=3,<5", "six>=1,<2", "decorator>=4,<5"],
+    install_requires=["pytest>=3,<5", "six>=1,<2", "decorator>=4"],
     classifiers=[
         "Development Status :: 5 - Production/Stable",
         "Framework :: Pytest",
