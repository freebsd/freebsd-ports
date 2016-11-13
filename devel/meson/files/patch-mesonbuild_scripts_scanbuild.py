From f7431fd5dba1f59ce70b07d7074999d1e7442887 Mon Sep 17 00:00:00 2001
From: Jussi Pakkanen <jpakkane@gmail.com>
Date: Wed, 9 Nov 2016 15:46:40 +0200
Subject: [PATCH] Can specify scan-build executable with an environment
 variable. Closes #1015.

--- mesonbuild/scripts/scanbuild.py.orig	2016-10-17 17:38:14 UTC
+++ mesonbuild/scripts/scanbuild.py
@@ -17,10 +17,10 @@ import subprocess
 import shutil
 import tempfile
 
-def scanbuild(srcdir, blddir, privdir, logdir, args):
+def scanbuild(exename, srcdir, blddir, privdir, logdir, args):
     with tempfile.TemporaryDirectory(dir=privdir) as scandir:
-        meson_cmd = ['scan-build'] + args
-        build_cmd = ['scan-build', '-o', logdir, 'ninja']
+        meson_cmd = [exename] + args
+        build_cmd = [exename, '-o', logdir, 'ninja']
         rc = subprocess.call(meson_cmd + [srcdir, scandir])
         if rc != 0:
             return rc
@@ -33,7 +33,8 @@ def run(args):
     privdir = os.path.join(blddir, 'meson-private')
     logdir = os.path.join(blddir, 'meson-logs/scanbuild')
     shutil.rmtree(logdir, ignore_errors=True)
-    if not shutil.which('scan-build'):
-        print('Scan-build not installed')
+    exename = os.environ.get('SCANBUILD', 'scan-build')
+    if not shutil.which(exename):
+        print('Scan-build not installed.')
         return 1
-    return scanbuild(srcdir, blddir, privdir, logdir, meson_cmd)
+    return scanbuild(exename, srcdir, blddir, privdir, logdir, meson_cmd)
