--- ./sonata.py.orig	2012-07-17 15:55:43.000000000 +0200
+++ ./sonata.py	2012-07-17 15:56:48.000000000 +0200
@@ -59,6 +59,8 @@
 # https://bugs.launchpad.net/ubuntu/+source/zsi/+bug/208855
 sys.path.append('/usr/lib/python2.5/site-packages/oldxml')
 
+sys.path.remove('%%PREFIX%%/bin')
+
 # hint for gnome.init to set the process name to 'sonata'
 if platform.system() == 'Linux':
 	sys.argv[0] = 'sonata'
