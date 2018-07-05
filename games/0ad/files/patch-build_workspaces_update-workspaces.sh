--- build/workspaces/update-workspaces.sh.orig	2014-09-20 19:02:24 UTC
+++ build/workspaces/update-workspaces.sh
@@ -1,10 +1,5 @@
 #!/bin/sh
 
-if [ "$(id -u)" = "0" ]; then
-   echo "Running as root will mess up file permissions. Aborting ..." 1>&2
-   exit 1
-fi
-
 die()
 {
   echo ERROR: $*
