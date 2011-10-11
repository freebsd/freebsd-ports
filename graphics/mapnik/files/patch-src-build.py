--- src/build.py.orig	2011-09-26 14:30:13.000000000 +0400
+++ src/build.py	2011-10-08 19:52:17.875391466 +0400
@@ -79,6 +79,8 @@
 
 if env['PLATFORM'] == 'Darwin':
     mapnik_libname = 'libmapnik2.dylib'
+elif env['PLATFORM'] == 'FreeBSD':
+    mapnik_libname = 'libmapnik2.so.' + ("%d" % (ABI_VERSION[0])) 
 else:
     mapnik_libname = 'libmapnik2.so.' + ("%d.%d" % (ABI_VERSION[0],ABI_VERSION[1])) 
 
@@ -320,7 +322,10 @@
 
     major, minor, micro = ABI_VERSION
     
-    soFile = "%s.%d.%d.%d" % (os.path.basename(str(mapnik[0])), major, minor, micro)
+    if env['PLATFORM'] == 'FreeBSD':
+        soFile = "%s.%d" % (os.path.basename(str(mapnik[0])), major)
+    else:
+        soFile = "%s.%d.%d.%d" % (os.path.basename(str(mapnik[0])), major, minor, micro)
     target = os.path.join(env['MAPNIK_LIB_BASE_DEST'], soFile)
     
     if 'uninstall' not in COMMAND_LINE_TARGETS:
@@ -335,13 +340,17 @@
     target2 = os.path.join(env['MAPNIK_LIB_BASE_DEST'], os.path.basename(str(mapnik[0])))
     if 'uninstall' not in COMMAND_LINE_TARGETS:
         if 'install' in COMMAND_LINE_TARGETS:
-            link1 = env.Command(target1, target, symlink)
-            env.Alias(target='install', source=link1)
-            link2 = env.Command(target2, target1, symlink)
+            if env['PLATFORM'] == 'FreeBSD':
+                link2 = env.Command(target2, target, symlink)
+            else:
+                link1 = env.Command(target1, target, symlink)
+                env.Alias(target='install', source=link1)
+                link2 = env.Command(target2, target1, symlink)
             env.Alias(target='install', source=link2)
     # delete in reverse order..
     env['create_uninstall_target'](env, target2)
-    env['create_uninstall_target'](env, target1)
+    if env['PLATFORM'] != 'FreeBSD':
+        env['create_uninstall_target'](env, target1)
     env['create_uninstall_target'](env, target)
 
 else:
