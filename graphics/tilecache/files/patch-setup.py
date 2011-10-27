--- setup.py.orig	2011-10-18 15:02:11.000000000 +0200
+++ setup.py	2011-10-18 15:02:47.000000000 +0200
@@ -39,8 +35,7 @@
       url='http://tilecache.org/',
       long_description=readme,
       packages=['TileCache', 'TileCache.Caches', 'TileCache.Services', 'TileCache.Layers'],
-      scripts=['tilecache.cgi', 'tilecache.fcgi',
-               'tilecache_seed.py', 'tilecache_install_config.py', 
+      scripts=['tilecache_seed.py', 'tilecache_install_config.py', 
                'tilecache_clean.py', 'tilecache_http_server.py'],
       zip_safe=False,
       test_suite = 'tests.run_doc_tests',
