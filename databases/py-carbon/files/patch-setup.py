--- setup.py.orig	2013-08-20 17:37:08.000000000 +0000
+++ setup.py	2013-08-21 01:19:40.025390594 +0000
@@ -13,9 +13,9 @@
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('/var/db/graphite/storage/whisper',[]), ('/var/db/graphite/storage/lists',[]),
+                 ('/var/db/graphite/storage/log',[]), ('/var/db/graphite/storage/rrd',[]) ]
+conf_files = [ ('/usr/local/etc/carbon', glob('conf/*.example')) ]
 
 install_files = storage_dirs + conf_files
 
