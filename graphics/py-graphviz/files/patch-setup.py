--- setup.py.orig
+++ setup.py
@@ -20,8 +20,8 @@
     print "To install, run 'python setup.py install'"
     print
 
-library_path=None
-include_path=None
+#library_path=None
+#include_path=None
 
 
 # If the setup script couldn't find your graphviz installation you can
@@ -33,8 +33,8 @@
 #include_path='/usr/include/graphviz'
 
 # UNIX, Linux alternate
-#library_path='/usr/local/lib/graphviz'
-#include_path='/usr/local/include/graphviz'
+library_path='%%LOCALBASE%%/lib/graphviz'
+include_path='%%LOCALBASE%%/include/graphviz'
 
 # Mac OS X (Fink)
 #library_path='/sw/lib/graphviz'
