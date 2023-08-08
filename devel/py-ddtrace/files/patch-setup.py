--- setup.py.orig	2023-02-17 21:33:11 UTC
+++ setup.py
@@ -366,7 +366,6 @@ setup(
     cmdclass={
         "test": Tox,
         "build_ext": BuildExtCommand,
-        "build_py": LibraryDownloader,
         "clean": CleanLibraries,
     },
     entry_points={
