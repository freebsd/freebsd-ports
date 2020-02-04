--- setup.py.orig	2019-12-21 11:28:25 UTC
+++ setup.py
@@ -96,9 +96,6 @@ setup(
     py_modules=[splitext(basename(path))[0] for path in glob('src/*.py')],
     include_package_data=True,
     zip_safe=False,
-    setup_requires = [
-        'requests >= 2.7.0',
-    ],
     classifiers=[
         'Intended Audience :: Developers',
         'License :: OSI Approved :: MIT License',
@@ -113,5 +110,4 @@ setup(
     keywords=[
         'domain', 'public suffix', 'suffix', 'dns', 'tld', 'sld', 'psl', 'idna',
     ],
-    cmdclass={'update_psl': UpdatePslCommand},
 )
