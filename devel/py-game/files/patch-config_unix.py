
$FreeBSD$

--- config_unix.py.orig	Sat Mar 23 10:23:12 2002
+++ config_unix.py	Tue May 28 12:58:39 2002
@@ -113,7 +113,7 @@
 
 sdl_lib_name = 'SDL'
 if sys.platform.find('bsd') != -1:
-    sdl_lib_name = 'SDL-1.2'
+    sdl_lib_name = 'SDL-1.1'
 
 
 def main():
@@ -132,8 +132,8 @@
         raise SystemExit
 
 
-    if localbase: #unneeded?
-        incdirs = [localbase + '/include/SDL']
+    if localbase: #unneeded? nah, needed on FreeBSD!
+        incdirs = [localbase + '/include/SDL11', localbase + '/include/smpeg']
         libdirs = [localbase + '/lib']
     else:
         incdirs = []
