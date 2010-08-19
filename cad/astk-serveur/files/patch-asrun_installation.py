--- ./asrun/installation.py.orig	2010-07-07 18:18:08.000000000 +0200
+++ ./asrun/installation.py	2010-08-11 22:01:50.000000000 +0200
@@ -19,7 +19,7 @@
 prefix = aster_root
 if aster_root == '/usr':
     prefix = '/'
-confdir = os.path.join(prefix, 'etc', 'codeaster')
+confdir = os.path.join(aster_root, 'etc', 'codeaster')
 
 # directory containing data files
 datadir = os.path.join(aster_root, 'share', 'codeaster', 'asrun', 'data')
