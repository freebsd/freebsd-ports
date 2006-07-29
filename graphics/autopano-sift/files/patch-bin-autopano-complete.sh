--- bin/autopano-complete.sh.orig	Sat Apr  9 05:40:12 2005
+++ bin/autopano-complete.sh	Wed Apr 12 12:14:10 2006
@@ -7,10 +7,10 @@
 MONO=$(which mono)
 
 # Set this to the directory you installed autopano-sift into, for example
-#AUTOPANO_PATH=/usr/local/autopano-sift/bin
+AUTOPANO_PATH=/usr/local/share/autopano-sift
 # Do not use a trailing backslash. If the executeables are within your path
 # (recommended, you can leave the line below).
-AUTOPANO_PATH=$(dirname $(which generatekeys.exe))
+#AUTOPANO_PATH=$(dirname $(which generatekeys.exe))
 
 usage()
 {
