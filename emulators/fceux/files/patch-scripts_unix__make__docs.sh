--- scripts/unix_make_docs.sh.orig	2022-01-21 21:26:16 UTC
+++ scripts/unix_make_docs.sh
@@ -1,13 +1,8 @@
 #!/bin/bash
 
-PROJECT_ROOT=$( cd "$(dirname ${BASH_SOURCE[0]})"/.. && pwd )
+cd $PROJECT_ROOT/web
 
-echo $PROJECT_ROOT;
-echo "Building for OS: $OSTYPE";
-
-cd $PROJECT_ROOT/web;
-
-qhelpgenerator fceux.qhcp -o fceux.qhc
+${QHELPGENERATOR} fceux.qhcp -o fceux.qhc
 
 cp -f fceux.qhc  $PROJECT_ROOT/output
 cp -f fceux.qch  $PROJECT_ROOT/output
