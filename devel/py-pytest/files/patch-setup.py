--- setup.py.orig	2016-02-27 05:10:48 UTC
+++ setup.py
@@ -69,7 +69,9 @@ def main():
         platforms=['unix', 'linux', 'osx', 'cygwin', 'win32'],
         author='Holger Krekel, Bruno Oliveira, Ronny Pfannschmidt, Floris Bruynooghe, Brianna Laugher, Florian Bruhin and others',
         author_email='holger at merlinux.eu',
-        entry_points=make_entry_points(),
+        entry_points= {
+            'console_scripts': ['py.test=pytest:main'],
+        },
         classifiers=classifiers,
         cmdclass={'test': PyTest},
         # the following should be enabled for release
