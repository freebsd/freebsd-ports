--- docs/conf.py.orig	2023-01-23 19:00:55 UTC
+++ docs/conf.py
@@ -11,7 +11,6 @@
 # All configuration values have a default; values that are commented out
 # serve to show the default.
 
-import spotipy
 import sys
 import os
 
@@ -19,8 +18,9 @@ import os
 # add these directories to sys.path here. If the directory is relative to the
 # documentation root, use os.path.abspath to make it absolute, like shown here.
 #sys.path.insert(0, os.path.abspath('.'))
-sys.path.insert(0, os.path.abspath('.'))
+sys.path.insert(0, os.path.abspath(os.path.join('..')))
 
+import spotipy
 # -- General configuration -----------------------------------------------------
 
 # If your documentation needs a minimal Sphinx version, state it here.
