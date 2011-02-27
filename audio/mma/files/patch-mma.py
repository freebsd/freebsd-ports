--- ./mma.py.orig	2011-02-27 11:14:24.000000000 +0100
+++ ./mma.py	2011-02-27 11:17:00.000000000 +0100
@@ -67,6 +67,9 @@
     dirlist = ( sys.path[0], "/Users/Shared/mma", 
              "/usr/local/share/mma", "/usr/share/mma", '.' )
     midiPlayer = ['']   # must be a list!
+elif platform == 'FreeBSD':
+    dirlist = ( sys.path[0], '%%DATADIR%%', '.' )
+    midiPlayer = ['timidity', 'playmidi']
 else:
     dirlist = ( sys.path[0], "/usr/local/share/mma", "/usr/share/mma", '.' )
     midiPlayer = ["aplaymidi"] # Must be a list!
