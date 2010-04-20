--- download.py.orig	2010-04-20 10:40:10.000000000 +0800
+++ download.py	2010-04-20 10:40:21.000000000 +0800
@@ -12,7 +12,7 @@
 from src.mapDownloader import MapDownloader
 
 mConf = mapConf.MapConf()
-ctx_map = MapServ(conf.init_path, conf.repository_type)
+ctx_map = MapServ(mConf.init_path, mConf.repository_type)
 downloader = None
 
 def do_nothing(*args, **kwargs):
