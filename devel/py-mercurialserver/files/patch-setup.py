--- ./setup.py.orig	2010-11-06 17:40:20.926497770 +0200
+++ ./setup.py	2010-11-06 17:40:39.706412807 +0200
@@ -13,7 +13,7 @@
     requires = ["mercurial"], # FIXME: what version?
     scripts = ['src/hg-ssh', 'src/refresh-auth'],
     data_files = [
-        ('init', [
+        ('hg', [
             'src/init/hginit', 
             'src/init/dot-mercurial-server', 
             'src/init/hgadmin-hgrc'
