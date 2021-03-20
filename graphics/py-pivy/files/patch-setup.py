--- setup.py.orig	2021-03-19 15:41:45 UTC
+++ setup.py
@@ -201,8 +201,8 @@ class pivy_build(build):
         print(yellow('calling: ' + cmake_command[0] + ' ' + cmake_command[1]))
         cmake = subprocess.Popen(cmake_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
         cmake_out, cmake_err = cmake.communicate()
-        coin_vars = ['COIN_FOUND', 'COIN_VERSION', 'COIN_INCLUDE_DIR', 'COIN_LIB_DIR']
-        soqt_vars = ['SOQT_FOUND', 'SOQT_VERSION', 'SOQT_INCLUDE_DIR', 'SOQT_LIB_DIR']
+        coin_vars = ['COIN_FOUND', 'COIN_INCLUDE_DIR', 'COIN_LIB_DIR']
+        soqt_vars = ['SOQT_VERSION', 'SOQT_INCLUDE_DIR', 'SOQT_LIB_DIR']
         config_dict = {}
         print(yellow(cmake_out.decode("utf-8")))
         print(red(cmake_err.decode("utf-8")))
@@ -228,7 +228,7 @@ class pivy_build(build):
             if key in config_dict:
                 print(blue(key + ': ' + config_dict[key]))
 
-        if config_dict.get('SOQT_FOUND', 'false') == 'false':
+        if config_dict.get('SOQT_INCLUDE_DIR', 'false') == 'false':
             pivy_build.MODULES.pop('soqt')
             print(red("\ndisable soqt, because cmake couldn't find it"))
         else:
