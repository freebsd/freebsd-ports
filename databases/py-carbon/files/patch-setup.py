--- setup.py.ori	2012-06-21 16:04:03.284808706 -0700
+++ setup.py	2012-06-21 16:05:09.681811949 -0700
@@ -12,9 +12,9 @@
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('/var/db/graphite/storage/whisper',[]), ('/var/db/graphite/storage/lists',[]),
+                 ('/var/db/graphite/storage/log',[]), ('/var/db/graphite/storage/rrd',[]) ]
+conf_files = [ ('/usr/local/etc/carbon', glob('conf/*.example')) ]
 #XXX Need a way to have these work for bdist_rpm but be left alone for everything else
 #init_scripts = [ ('/etc/init.d', ['distro/redhat/init.d/carbon-cache',
 #                                  'distro/redhat/init.d/carbon-relay',
