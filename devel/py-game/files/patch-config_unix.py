
$FreeBSD$

--- config_unix.py.orig	Sat Nov  3 19:27:56 2001
+++ config_unix.py	Wed Dec 19 14:49:24 2001
@@ -43,7 +43,7 @@
 
 sdl_lib_name = 'SDL'
 if sys.platform.find('bsd') != -1:
-    sdl_lib_name = 'SDL-1.2'
+    sdl_lib_name = 'SDL-1.1'
 
 DEPS = [
     Dependency('SDL', 'SDL.h', 'lib'+sdl_lib_name+'.so', sdl_lib_name),
@@ -74,7 +74,7 @@
 
     print 'Hunting dependencies...'
     if localbase:
-        incdirs = [localbase + '/include/SDL']
+        incdirs = [localbase + '/include/SDL11', localbase + '/include/smpeg']
         libdirs = [localbase + '/lib']
     else:
         incdirs = []
