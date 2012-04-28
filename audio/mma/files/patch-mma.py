$FreeBSD$
--- ./mma.py.orig	2012-04-28 14:45:21.000000000 +0200
+++ ./mma.py	2012-04-28 14:46:09.000000000 +0200
@@ -67,6 +67,9 @@
     dirlist = ( sys.path[0], "/Users/Shared/mma", 
              "/usr/local/share/mma", "/usr/share/mma", '.' )
     midiPlayer = ['open']   # must be a list!
+elif platform == 'FreeBSD':
+    dirlist = ( sys.path[0], '%%DATADIR%%', '.' )
+    midiPlayer = ['timidity', 'playmidi']
 else:
     dirlist = ( sys.path[0], "/usr/local/share/mma", "/usr/share/mma", '.' )
     midiPlayer = ["aplaymidi"] # Must be a list!
