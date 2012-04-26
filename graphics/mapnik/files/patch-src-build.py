--- src/build.py.orig	2012-04-11 14:29:19.000000000 +0400
+++ src/build.py	2012-04-11 14:34:13.000000000 +0400
@@ -80,6 +80,8 @@
 
 if env['PLATFORM'] == 'Darwin':
     mapnik_libname = 'libmapnik.dylib'
+elif env['PLATFORM'] == 'FreeBSD':
+    mapnik_libname = 'libmapnik.so.' + ("%d" % int(ABI_VERSION[0]))
 else:
     mapnik_libname = 'libmapnik.so.' + ("%d.%d" % (int(ABI_VERSION[0]),int(ABI_VERSION[1])))
 
@@ -326,8 +328,12 @@
         os.symlink(os.path.basename(src), trgt)
 
     major, minor, micro = ABI_VERSION
-    
-    soFile = "%s.%d.%d.%d" % (os.path.basename(str(mapnik[0])), int(major), int(minor), int(micro))
+
+    if env['PLATFORM'] == 'FreeBSD':
+        soFile = "%s.%d" % (os.path.basename(str(mapnik[0])), int(major))
+    else:
+        soFile = "%s.%d.%d.%d" % (os.path.basename(str(mapnik[0])), int(major), int(minor), int(micro))
+   
     target = os.path.join(env['MAPNIK_LIB_BASE_DEST'], soFile)
     
     if 'uninstall' not in COMMAND_LINE_TARGETS:
@@ -342,13 +348,17 @@
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
