--- setup.py.orig	2011-04-03 22:20:13.000000000 -0400
+++ setup.py	2011-05-05 22:03:42.000000000 -0400
@@ -12,9 +12,9 @@
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('/var/db/graphite/storage/whisper',[]), ('/var/db/graphite/storage/lists',[]),
+                 ('/var/db/graphite/storage/log',[]), ('/var/db/graphite/storage/rrd',[]) ]
+conf_files = [ ('/usr/local/etc/carbon', glob('conf/*.example')) ]
 
 setup(
   name='carbon',
