--- buildtools/mkversion.sh.orig	2021-10-05 14:58:58 UTC
+++ buildtools/mkversion.sh
@@ -1,6 +1,7 @@
 #!/bin/sh
 
-STATUS=`git status 2>&1`
+#STATUS=`git status 2>&1`
+false
 if [ $? -eq 0 ]; then
   echo "Building version info from git"
   HASH=`git show --format=%H | head -1`
