--- setup.py.orig	2023-11-01 20:05:58 UTC
+++ setup.py
@@ -250,7 +250,7 @@ if sys.version_info < (2, 4):
         return iterable
 
 
-setup(name="PyICU",
+setup(name="pyicu",
       description='Python extension wrapping the ICU C++ API',
       long_description=open('README.md').read(),
       long_description_content_type="text/markdown",
