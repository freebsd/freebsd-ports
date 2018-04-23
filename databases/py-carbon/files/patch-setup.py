--- setup.py.orig	2018-04-04 03:38:32.000000000 -0400
+++ setup.py	2018-04-23 12:08:38.358102000 -0400
@@ -58,10 +58,10 @@ else:
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/ceres/dummy.txt', []), ('storage/whisper/dummy.txt',[]),
-                 ('storage/lists',[]), ('storage/log/dummy.txt',[]),
-                 ('storage/rrd/dummy.txt',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('/var/db/carbon/ceres',[]),  ('/var/db/carbon/whisper',[]),
+                 ('/var/db/carbon/lists',[]), ('/var/db/carbon/log',[]),
+                 ('/var/db/carbon/rrd',[]) ]
+conf_files = [ ('%%PREFIX%%/etc/carbon', glob('conf/*.example')) ]
 
 install_files = storage_dirs + conf_files
 
