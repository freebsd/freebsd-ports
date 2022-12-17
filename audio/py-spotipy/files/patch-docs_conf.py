--- docs/conf.py.orig	2022-12-10 15:31:47 UTC
+++ docs/conf.py
@@ -17,7 +17,7 @@ import sys, os
 # add these directories to sys.path here. If the directory is relative to the
 # documentation root, use os.path.abspath to make it absolute, like shown here.
 #sys.path.insert(0, os.path.abspath('.'))
-sys.path.insert(0, os.path.abspath('.'))
+sys.path.insert(0, os.path.abspath(os.path.join('..')))
 import spotipy
 
 # -- General configuration -----------------------------------------------------
