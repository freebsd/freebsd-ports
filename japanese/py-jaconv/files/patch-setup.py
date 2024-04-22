--- setup.py.orig	2023-02-17 17:05:21 UTC
+++ setup.py
@@ -39,7 +39,7 @@ setup(name='jaconv',
           'Programming Language :: Python :: 3.10',
           'Programming Language :: Python :: 3.11', 'Topic :: Text Processing'
       ],
-      data_files=[('', ['README.rst', 'CHANGES.rst'])],
+      package_data={'': ['README.rst', 'CHANGES.rst']},
       long_description='%s\n\n%s' %
       (open('README.rst', encoding='utf8').read(),
        open('CHANGES.rst', encoding='utf8').read()),
