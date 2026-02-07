--- setup.py.orig	2020-01-29 13:22:11 UTC
+++ setup.py
@@ -34,12 +34,5 @@ use.''',
       ],
       packages = ['iniparse'],
       install_requires=['six'],
-      data_files = [
-        ('share/doc/iniparse-%s' % VERSION, ['README.md', 'LICENSE-PSF',
-                                             'LICENSE', 'Changelog',
-                                             'html/index.html',
-                                             'html/style.css',
-                                             ]),
-      ],
 )
 
