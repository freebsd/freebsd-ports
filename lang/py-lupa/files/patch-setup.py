Obtained from:  https://github.com/scoder/lupa/commit/19279acda1ad7e7a536adafe399b183701287bc1

--- setup.py.orig	2023-04-04 07:12:27 UTC
+++ setup.py
@@ -365,10 +365,11 @@ if not configs and not option_no_bundle:
             or (get_machine() != "x86_64" and 'luajit' in os.path.basename(lua_bundle_path.rstrip(os.sep)))
         )
     ]
-if not configs and not option_use_bundle:
-    configs = find_lua_build(no_luajit=option_no_luajit)
 if not configs:
-    configs = no_lua_error()
+    configs = [
+        (find_lua_build(no_luajit=option_no_luajit) if not option_use_bundle else {})
+        or no_lua_error()
+    ]
 
 
 # check if Cython is installed, and use it if requested or necessary
@@ -484,7 +485,7 @@ setup(
     ],
 
     packages=['lupa'],
-    build_requires=['Cython>=0.29.28'],
+    setup_requires=['Cython>=0.29.28'],
     ext_modules=ext_modules,
     libraries=ext_libraries,
     **extra_setup_args
