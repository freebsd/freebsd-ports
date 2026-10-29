--- scripts/prep-fle-addon.sh.orig
+++ scripts/prep-fle-addon.sh
@@ -20,6 +20,9 @@
 # This isn't a lot, but hopefully after https://jira.mongodb.org/browse/WRITING-7164
 # we'll be able to simplify this further.
 
+# The port links against the system libmongocrypt instead of cloning and
+# building a static copy of it.
+if [ "$(uname)" != FreeBSD ]; then
 cd "$(dirname "$0")"/..
 MONGOSH_ROOT_DIR="$PWD"
 BUILDROOT="$MONGOSH_ROOT_DIR"/tmp/fle-buildroot
@@ -83,3 +86,4 @@
   fi
   cp -rv ./deps/include/*mongocrypt* "$FLE_NODE_SOURCE_PATH"/deps/include
 fi
+fi
