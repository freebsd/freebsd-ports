--- setup.py.orig	Sun May 27 19:36:23 2007
+++ setup.py	Sun May 27 19:36:44 2007
@@ -45,7 +45,7 @@
 #
 mo_files = ["locale/%s/LC_MESSAGES/PyTone.mo" % locale for locale in locales]
 data_files=[('share/locale/de/LC_MESSAGES', mo_files),
-            ('/etc', ['conf/pytonerc'])]
+            ('etc', ['conf/pytonerc'])]
 
 #
 # list of scripts to be installed
