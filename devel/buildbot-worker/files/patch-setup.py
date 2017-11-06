--- setup.py.orig	2017-07-01 19:16:48 UTC
+++ setup.py
@@ -106,9 +106,6 @@ setup_args = {
         "buildbot_worker.test.unit",
         "buildbot_worker.test.util",
     ],
-    # mention data_files, even if empty, so install_data is called and
-    # VERSION gets copied
-    'data_files': [("buildbot_worker", [])],
     'cmdclass': {
         'install_data': our_install_data,
         'sdist': our_sdist
