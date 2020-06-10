--- setup.py.orig	2020-03-16 15:22:22 UTC
+++ setup.py
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
 
