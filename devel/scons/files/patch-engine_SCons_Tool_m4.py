--- engine/SCons/Tool/m4.py.orig	2013-03-03 14:48:40.000000000 +0000
+++ engine/SCons/Tool/m4.py
@@ -49,7 +49,7 @@ def generate(env):
     # file and run from there.
     # The src_suffix setup is like so: file.c.m4 -> file.c,
     # file.cpp.m4 -> file.cpp etc.
-    env['M4']      = 'm4'
+    env['M4']      = 'gm4'
     env['M4FLAGS'] = SCons.Util.CLVar('-E')
     env['M4COM']   = 'cd ${SOURCE.rsrcdir} && $M4 $M4FLAGS < ${SOURCE.file} > ${TARGET.abspath}'
 
