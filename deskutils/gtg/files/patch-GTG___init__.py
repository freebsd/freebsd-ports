--- GTG/__init__.py.orig	2009-03-07 02:09:57.000000000 +0300
+++ GTG/__init__.py	2009-03-16 01:19:21.000000000 +0300
@@ -22,7 +22,7 @@
 EMAIL           = "gtg@lists.launchpad.net"
 VERSION         = '0.1'
 LOCAL_ROOTDIR   = os.path.abspath(os.path.join(os.path.dirname(__file__), '..')) 
-DIST_ROOTDIR    = "/usr/share/gtg"
+DIST_ROOTDIR    = "/usr/local/share/gtg"
 
 if not os.path.isdir( os.path.join(LOCAL_ROOTDIR,'data') ) :
     DATA_DIR = DIST_ROOTDIR
