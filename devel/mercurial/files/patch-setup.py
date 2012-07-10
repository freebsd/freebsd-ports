--- setup 1.py	2012-06-02 08:48:21.000000000 +0400
+++ setup.py	2012-06-12 17:05:27.091982103 +0400
@@ -223,6 +223,7 @@
     description = "build translations (.mo files)"
 
     def run(self):
+%%NLS%%        return
         if not find_executable('msgfmt'):
             self.warn("could not find msgfmt executable, no translations "
                      "will be built")
@@ -385,7 +386,7 @@
             'install_scripts': hginstallscripts}
 
 packages = ['mercurial', 'mercurial.hgweb',
-            'mercurial.httpclient', 'mercurial.httpclient.tests',
+            'mercurial.httpclient',
             'hgext', 'hgext.convert', 'hgext.highlight', 'hgext.zeroconf',
             'hgext.largefiles']
 
