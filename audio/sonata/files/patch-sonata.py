--- sonata.py.orig	2009-09-21 21:02:16 UTC
+++ sonata.py
@@ -59,6 +59,8 @@ except ImportError:
 # https://bugs.launchpad.net/ubuntu/+source/zsi/+bug/208855
 sys.path.append('/usr/lib/python2.5/site-packages/oldxml')
 
+sys.path.remove('%%PREFIX%%/bin')
+
 # hint for gnome.init to set the process name to 'sonata'
 if platform.system() == 'Linux':
 	sys.argv[0] = 'sonata'
