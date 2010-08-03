--- setup.py.orig	2010-08-01 21:18:02.000000000 +0800
+++ setup.py	2010-08-02 15:59:57.000000000 +0800
@@ -28,8 +28,8 @@
           sys.version_info[:2]
     sys.exit(-1)
 
-library_path=None
-include_path=None
+#library_path=None
+#include_path=None
 
 # If the setup script couldn't find your graphviz installation you can
 # specify it here by uncommenting these lines or providing your own:
@@ -42,6 +42,8 @@
 # OSX, Linux, alternate location
 #library_path='/usr/local/lib/graphviz'
 #include_path='/usr/local/include/graphviz'
+library_path='%%LOCALBASE%%/lib/graphviz'
+include_path='%%LOCALBASE%%/include/graphviz'
 
 # OSX (Fink)
 #library_path='/sw/lib/graphviz'
