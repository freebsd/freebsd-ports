--- setup.py.orig	2012-02-01 21:23:54.000000000 +0100
+++ setup.py	2012-02-02 12:44:12.000000000 +0100
@@ -379,7 +379,7 @@
             'install_scripts': hginstallscripts}
 
 packages = ['mercurial', 'mercurial.hgweb',
-            'mercurial.httpclient', 'mercurial.httpclient.tests',
+            'mercurial.httpclient',
             'hgext', 'hgext.convert', 'hgext.highlight', 'hgext.zeroconf',
             'hgext.largefiles']
 
