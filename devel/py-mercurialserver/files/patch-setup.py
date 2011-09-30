--- ./setup.py.orig	2011-09-06 13:40:10.000000000 +0300
+++ ./setup.py	2011-09-20 11:01:50.960960465 +0300
@@ -7,13 +7,13 @@
     name="mercurial-server",
     description="Centralized Mercurial repository manager",
     url="http://www.lshift.net/mercurial-server.html",
-    version="1.1", # FIXME: infer this
+    version="1.2", # FIXME: infer this
     package_dir = {'': 'src'},
     packages = ["mercurialserver"],
     requires = ["mercurial"], # FIXME: what version?
     scripts = ['src/hg-ssh', 'src/refresh-auth'],
     data_files = [
-        ('init', [
+        ('etc/mercurialserver', [
             'src/init/hginit',
             'src/init/dot-mercurial-server',
             'src/init/hgadmin-hgrc'
