--- setup/install.py.orig	2013-09-06 06:28:39.000000000 +0200
+++ setup/install.py	2013-09-10 22:34:23.970135119 +0200
@@ -160,7 +160,7 @@
         self.info('Installing mount helper to '+ dest)
         cflags = os.environ.get('OVERRIDE_CFLAGS', '-Wall -pedantic')
         cflags = shlex.split(cflags)
-        p = subprocess.Popen(['gcc']+cflags+[src, '-o', dest])
+        p = subprocess.Popen([os.getenv('CC', 'gcc')]+cflags+[src, '-o', dest])
         ret = p.wait()
         if ret != 0:
             return warn()
