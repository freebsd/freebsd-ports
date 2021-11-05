Obtained from:  https://github.com/pypa/packaging/commit/8cb9dbf19e2b76ab025efc11208bd50e09e8223e

--- setup.py.orig	2021-10-29 11:19:27 UTC
+++ setup.py
@@ -48,7 +48,7 @@ setup(
     author=about["__author__"],
     author_email=about["__email__"],
     python_requires=">=3.6",
-    install_requires=["pyparsing>=2.0.2,<3"],  # Needed to avoid issue #91
+    install_requires=["pyparsing>=2.0.2"],  # Needed to avoid issue #91
     classifiers=[
         "Development Status :: 5 - Production/Stable",
         "Intended Audience :: Developers",
