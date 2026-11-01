--- scripts/prep-fle-addon.sh.orig	2026-09-17 07:24:06 UTC
+++ scripts/prep-fle-addon.sh
@@ -20,6 +20,7 @@ set -x
 # This isn't a lot, but hopefully after https://jira.mongodb.org/browse/WRITING-7164
 # we'll be able to simplify this further.
 
+if [ "$(uname)" != FreeBSD ]; then
 cd "$(dirname "$0")"/..
 MONGOSH_ROOT_DIR="$PWD"
 BUILDROOT="$MONGOSH_ROOT_DIR"/tmp/fle-buildroot
@@ -82,4 +83,5 @@ if [ x"$FLE_NODE_SOURCE_PATH" != x"" ]; then
     cp -rv ./deps/include/*kms* "$FLE_NODE_SOURCE_PATH"/deps/include
   fi
   cp -rv ./deps/include/*mongocrypt* "$FLE_NODE_SOURCE_PATH"/deps/include
+fi
 fi
