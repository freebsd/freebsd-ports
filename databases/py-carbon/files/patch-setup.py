--- setup.py.orig	2015-11-27 18:37:07 UTC
+++ setup.py
@@ -13,9 +13,9 @@ else:
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('/var/db/carbon/whisper',[]), ('/var/db/carbon/lists',[]),
+                 ('/var/db/carbon/log',[]), ('/var/db/carbon/rrd',[]) ]
+conf_files = [ ('/usr/local/etc/carbon', glob('conf/*.example')) ]
 
 install_files = storage_dirs + conf_files
 
