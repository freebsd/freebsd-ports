--- src/build.py.orig	2012-08-24 01:57:06.000000000 +0400
+++ src/build.py	2012-09-16 19:38:43.000000000 +0400
@@ -357,7 +357,11 @@
 
     major, minor, micro = ABI_VERSION
 
-    soFile = "%s.%d.%d.%d" % (os.path.basename(env.subst(env['MAPNIK_LIB_NAME'])), int(major), int(minor), int(micro))
+    if env['PLATFORM'] == 'FreeBSD':
+        soFile = "%s.%d.%d" % (os.path.basename(env.subst(env['MAPNIK_LIB_NAME'])), int(major), int(minor))
+    else:
+        soFile = "%s.%d.%d.%d" % (os.path.basename(env.subst(env['MAPNIK_LIB_NAME'])), int(major), int(minor), int(micro))
+
     target = os.path.join(env['MAPNIK_LIB_BASE_DEST'], soFile)
 
     if 'uninstall' not in COMMAND_LINE_TARGETS:
@@ -372,8 +376,13 @@
 
 
     # Install symlinks
-    target1 = os.path.join(env['MAPNIK_LIB_BASE_DEST'], "%s.%d.%d" % \
-        (os.path.basename(env.subst(env['MAPNIK_LIB_NAME'])),int(major), int(minor)))
+    if env['PLATFORM'] == 'FreeBSD':
+        target1 = os.path.join(env['MAPNIK_LIB_BASE_DEST'], "%s.%d" % \
+              (os.path.basename(env.subst(env['MAPNIK_LIB_NAME'])),int(major)))
+    else:
+        target1 = os.path.join(env['MAPNIK_LIB_BASE_DEST'], "%s.%d.%d" % \
+              (os.path.basename(env.subst(env['MAPNIK_LIB_NAME'])),int(major), int(minor)))
+
     target2 = os.path.join(env['MAPNIK_LIB_BASE_DEST'], os.path.basename(env.subst(env['MAPNIK_LIB_NAME'])))
     if 'uninstall' not in COMMAND_LINE_TARGETS:
         link1 = env.Command(target1, target, symlink)
