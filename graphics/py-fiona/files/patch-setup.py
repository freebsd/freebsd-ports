Obtained from:	https://github.com/Toblerity/Fiona/commit/99fa8c27e6f8f8d1dba428fe123878cf9bb5bba3

--- setup.py.orig	2018-07-17 18:09:40 UTC
+++ setup.py
@@ -181,6 +181,14 @@ ext_options = dict(
     extra_link_args=extra_link_args,
 )
 
+ext_options_cpp = ext_options.copy()
+# GDAL 2.3+ requires C++11
+if sys.platform == "win32":
+    ext_options_cpp["extra_compile_args"] = ["/std:c++11"]
+else:
+    ext_options_cpp["extra_compile_args"] = ["-std=c++11"]
+
+
 # Define the extension modules.
 ext_modules = []
 
@@ -207,7 +215,7 @@ if source_is_repo and "clean" not in sys
 
     ext_modules = cythonize([
         Extension('fiona._geometry', ['fiona/_geometry.pyx'], **ext_options),
-        Extension('fiona._transform', ['fiona/_transform.pyx'], **ext_options),
+        Extension('fiona._transform', ['fiona/_transform.pyx'], **ext_options_cpp),
         Extension('fiona._crs', ['fiona/_crs.pyx'], **ext_options),
         Extension('fiona._drivers', ['fiona/_drivers.pyx'], **ext_options),
         Extension('fiona._err', ['fiona/_err.pyx'], **ext_options),
@@ -217,7 +225,7 @@ if source_is_repo and "clean" not in sys
 # If there's no manifest template, as in an sdist, we just specify .c files.
 elif "clean" not in sys.argv:
     ext_modules = [
-        Extension('fiona._transform', ['fiona/_transform.cpp'], **ext_options),
+        Extension('fiona._transform', ['fiona/_transform.cpp'], **ext_options_cpp),
         Extension('fiona._geometry', ['fiona/_geometry.c'], **ext_options),
         Extension('fiona._crs', ['fiona/_crs.c'], **ext_options),
         Extension('fiona._drivers', ['fiona/_drivers.c'], **ext_options),
