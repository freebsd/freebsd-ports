--- setup.py.orig
+++ setup.py
@@ -30,12 +30,5 @@
         'Topic :: Software Development :: Libraries :: Python Modules',
       ],
       packages = ['iniparse'],
-      data_files = [
-        ('share/doc/iniparse-%s' % VERSION, ['README', 'LICENSE-PSF',
-                                             'LICENSE', 'Changelog',
-                                             'html/index.html',
-                                             'html/style.css',
-                                             ]),
-      ],
 )
 
