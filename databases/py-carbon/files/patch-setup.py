--- setup.py.orig	2017-07-11 17:42:10.000000000 -0400
+++ setup.py	2017-10-18 10:23:03.662885000 -0400
@@ -50,12 +50,11 @@
   from distutils.core import setup
   setup_kwargs = dict()
 
-
-storage_dirs = [ ('storage/ceres', []), ('storage/whisper',[]),
-                 ('storage/lists',[]), ('storage/log',[]),
-                 ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
-
+storage_dirs = [ ('/var/db/carbon/ceres',[]),  ('/var/db/carbon/whisper',[]),
+                 ('/var/db/carbon/lists',[]), ('/var/db/carbon/log',[]),
+                 ('/var/db/carbon/rrd',[]) ]
+conf_files = [ ('%%PREFIX%%/etc/carbon', glob('conf/*.example')) ]
+ 
 install_files = storage_dirs + conf_files
 
 # Let's include redhat init scripts, despite build platform
