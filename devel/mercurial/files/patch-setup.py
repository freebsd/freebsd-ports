--- setup.py.orig	2012-08-02 10:49:31.000000000 +0400
+++ setup.py	2012-08-08 18:34:01.000000000 +0400
@@ -227,6 +227,7 @@
     description = "build translations (.mo files)"
 
     def run(self):
+        %%NLS%%return
         if not find_executable('msgfmt'):
             self.warn("could not find msgfmt executable, no translations "
                      "will be built")
