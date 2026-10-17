Description: Do not install the top-level tests package.
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits since 2018-12); keep locally.

--- setup.py.orig	2026-10-12 14:27:53 UTC
+++ setup.py
@@ -24,7 +24,7 @@ setup(name="pyformance",
       author="Omer Getrel",
       author_email="omer.gertel@gmail.com",
       version=__version__,
-      packages=find_packages(),
+      packages=find_packages(exclude=["tests", "tests.*"]),
       data_files=[],
       install_requires=install_requires,
       scripts=[],
