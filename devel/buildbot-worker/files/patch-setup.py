--- setup.py.orig	2017-02-08 10:06:13.000000000 +0100
+++ setup.py	2017-03-07 15:28:03.225761995 +0100
@@ -104,9 +104,6 @@
         "buildbot_worker.test.unit",
         "buildbot_worker.test.util",
     ],
-    # mention data_files, even if empty, so install_data is called and
-    # VERSION gets copied
-    'data_files': [("buildbot_worker", [])],
     'cmdclass': {
         'install_data': our_install_data,
         'sdist': our_sdist
