--- setup.py.orig	2018-06-08 08:15:18 UTC
+++ setup.py
@@ -203,7 +203,7 @@ class pivy_build(build):
         print(yellow('calling: ' + cmake_command[0] + ' ' + cmake_command[1]))
         cmake = subprocess.Popen(cmake_command, stdout=subprocess.PIPE)
         cmake_out, _ = cmake.communicate()
-        coin_vars = ['COIN_FOUND', 'COIN_VERSION', 'COIN_INCLUDE_DIR', 'COIN_LIB_DIR']
+        coin_vars = ['COIN_FOUND', 'COIN_INCLUDE_DIR', 'COIN_LIB_DIR']
         soqt_vars = ['SOQT_FOUND', 'SOQT_VERSION', 'SOQT_INCLUDE_DIR', 'SOQT_LIB_DIR']
         config_dict = {}
         if cmake.returncode == 0:
