--- setup.py.orig	2016-11-28 02:44:17 UTC
+++ setup.py
@@ -102,7 +102,6 @@ if __name__ == "__main__":
     ctraits = Extension(
         'traits.ctraits',
         sources=['traits/ctraits.c'],
-        extra_compile_args=['-DNDEBUG=1', '-O3'],
         )
 
     def additional_commands():
