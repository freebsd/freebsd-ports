--- setup.py.orig	2023-10-07 19:31:53 UTC
+++ setup.py
@@ -173,7 +173,6 @@ class build_ext(_build_ext):
                 compiler_directives=dict(
                     binding=True,
                     language_level=2,
-                    legacy_implicit_noexcept=True,
                     ))
 
 
