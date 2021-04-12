--- setup.py.orig	2021-04-05 15:27:07 UTC
+++ setup.py
@@ -11,7 +11,6 @@ def main():
     setup(  name = "CrossMap",
             version = "0.5.2",
             python_requires='>=3.5',
-            py_modules = [ 'psyco_full' ],
             packages = find_packages( 'lib' ),
             package_dir = { '': 'lib' },
             package_data = { '': ['*.ps'] },
