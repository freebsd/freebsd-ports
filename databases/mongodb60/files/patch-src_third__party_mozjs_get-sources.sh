--- src/third_party/mozjs/get-sources.sh.orig	2022-09-08 09:53:27 UTC
+++ src/third_party/mozjs/get-sources.sh
@@ -12,9 +12,9 @@ LIB_GIT_REPO=git@github.com:mongodb-forks/spidermonkey
 LIB_GIT_REVISION=82aac6af18abcd5bf188afbc821779ccb0ca0902
 LIB_GIT_REPO=git@github.com:mongodb-forks/spidermonkey.git
 
-DEST_DIR=$(git rev-parse --show-toplevel)/src/third_party/mozjs
+DEST_DIR=$(realpath .)
 
-LIB_GIT_DIR=$(mktemp -d /tmp/import-spidermonkey.XXXXXX)
+LIB_GIT_DIR=$(mktemp -d /var/tmp/import-spidermonkey.XXXXXX)
 trap "rm -rf $LIB_GIT_DIR" EXIT
 
 git clone $LIB_GIT_REPO $LIB_GIT_DIR
