--- setup.py.orig	Sun Mar 12 23:09:05 2006
+++ setup.py	Sun Sep 24 15:05:50 2006
@@ -25,7 +19,7 @@
 
 # If setting the prefix failed you should attempt to set the prefix here:
 # prefix="/usr" # unix, Linux
-# prefix="/usr/local" # unix, alternate
+prefix="%%LOCALBASE%%" # unix, alternate
 # prefix="/sw"  # OSX, fink
 # prefix="/opt/local"  # OSX, darwin-ports? 
 
