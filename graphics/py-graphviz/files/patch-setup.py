
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -25,7 +25,7 @@
 
 # If setting the prefix failed you should attempt to set the prefix here:
 # prefix="/usr" # unix, Linux
-# prefix="/usr/local" # unix, alternate
+prefix="%%LOCALBASE%%" # unix, alternate
 # prefix="/sw"  # OSX, fink
 # prefix="/opt/local"  # OSX, darwin-ports? 
 
