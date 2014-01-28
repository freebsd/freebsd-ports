--- ./setup.py.orig	2014-01-28 19:18:29.885753132 +1100
+++ ./setup.py	2014-01-28 19:18:53.182782954 +1100
@@ -96,9 +96,6 @@
         "buildslave.test.unit",
     ],
     'scripts': scripts,
-    # mention data_files, even if empty, so install_data is called and
-    # VERSION gets copied
-    'data_files': [("buildslave", [])],
     'cmdclass': {
         'install_data': our_install_data,
         'sdist': our_sdist
