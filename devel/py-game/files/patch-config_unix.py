
$FreeBSD$

--- config_unix.py	2001/09/03 13:07:39	1.1
+++ config_unix.py	2001/09/03 13:10:16
@@ -41,7 +41,7 @@
 
 sdl_lib_name = 'SDL'
 if sys.platform.find('bsd') != -1:
-    sdl_lib_name = 'SDL-1.2'
+    sdl_lib_name = 'SDL-1.1'
 
 DEPS = [
     Dependency('SDL', 'SDL.h', 'lib'+sdl_lib_name+'.so', sdl_lib_name),
