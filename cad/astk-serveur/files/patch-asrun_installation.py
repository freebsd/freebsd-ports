--- ./asrun/installation.py.orig	2011-12-20 13:33:00.000000000 +0100
+++ ./asrun/installation.py	2012-01-02 21:53:51.000000000 +0100
@@ -21,7 +21,7 @@
 prefix = aster_root
 if aster_root == '/usr':
     prefix = '/'
-confdir = osp.join(prefix, 'etc', 'codeaster')
+confdir = osp.join(aster_root, 'etc', 'codeaster')
 
 # confdir contains plugins directory
 if confdir not in sys.path:
