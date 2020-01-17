--- setup.py.orig	2020-01-12 21:51:59 UTC
+++ setup.py
@@ -201,7 +201,7 @@ class pivy_build(build):
         print(yellow('calling: ' + cmake_command[0] + ' ' + cmake_command[1]))
         cmake = subprocess.Popen(cmake_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
         cmake_out, cmake_err = cmake.communicate()
-        coin_vars = ['COIN_FOUND', 'COIN_VERSION', 'COIN_INCLUDE_DIR', 'COIN_LIB_DIR']
+        coin_vars = ['COIN_FOUND', 'COIN_INCLUDE_DIR', 'COIN_LIB_DIR']
         soqt_vars = ['SOQT_FOUND', 'SOQT_VERSION', 'SOQT_INCLUDE_DIR', 'SOQT_LIB_DIR']
         config_dict = {}
         print(yellow(cmake_out.decode("utf-8")))
