--- setup.py.orig	2010-10-15 12:57:57.000000000 +0200
+++ setup.py	2014-06-14 09:25:14.000000000 +0200
@@ -21,15 +21,15 @@
         'Topic :: Scientific/Engineering :: GIS',
 ]
 
-# We'd like to let debian install the /etc/tilecache.cfg,
+# We'd like to let debian install the /usr/local/etc/tilecache/tilecache.cfg,
 # but put them in tilecache/tilecache.cfg using setuptools
 # otherwise. 
 extra = { }
 if "--debian" in sys.argv:
-   extra['data_files']=[('/etc', ['tilecache.cfg']),('.',['dev.ini'])]
+   extra['data_files']=[('/usr/local/etc/tilecache', ['tilecache.cfg'])]
    sys.argv.remove("--debian")
 else:
-   extra['data_files']=[('TileCache', ['tilecache.cfg']),('.',['dev.ini'])]
+   extra['data_files']=[('TileCache', ['tilecache.cfg'])]
     
 setup(name='TileCache',
       version='2.11',
@@ -39,8 +39,7 @@
       url='http://tilecache.org/',
       long_description=readme,
       packages=['TileCache', 'TileCache.Caches', 'TileCache.Services', 'TileCache.Layers'],
-      scripts=['tilecache.cgi', 'tilecache.fcgi',
-               'tilecache_seed.py', 'tilecache_install_config.py', 
+      scripts=['tilecache_seed.py', 'tilecache_install_config.py', 
                'tilecache_clean.py', 'tilecache_http_server.py'],
       zip_safe=False,
       test_suite = 'tests.run_doc_tests',
