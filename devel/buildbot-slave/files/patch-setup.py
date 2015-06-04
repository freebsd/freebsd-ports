--- setup.py.orig	2014-04-20 08:52:42 UTC
+++ setup.py
@@ -99,9 +99,6 @@ setup_args = {
         "buildslave.test.unit",
     ],
     'scripts': scripts,
-    # mention data_files, even if empty, so install_data is called and
-    # VERSION gets copied
-    'data_files': [("buildslave", [])],
     'cmdclass': {
         'install_data': our_install_data,
         'sdist': our_sdist
