--- setup.py.orig	2024-07-25 16:31:04 UTC
+++ setup.py
@@ -43,7 +43,6 @@ setup(name='jaconv',
           'Programming Language :: Python :: 3.11',
           'Programming Language :: Python :: 3.12', 'Topic :: Text Processing'
       ],
-      data_files=[('', ['README.rst', 'CHANGES.rst'])],
       long_description='%s\n\n%s' %
       (open('README.rst', encoding='utf8').read(),
        open('CHANGES.rst', encoding='utf8').read()),
