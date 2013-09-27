--- deps/node_package/priv/base/env.sh.orig	2013-09-13 10:22:32.000000000 +0200
+++ deps/node_package/priv/base/env.sh	2013-09-13 10:27:16.000000000 +0200
@@ -100,7 +100,7 @@
 # read/write/delete .pid files during startup/shutdown
 create_pid_dir() {
     # Validate RUNNER_USER is set and they have permissions to write to /var/run
-    # Don't continue if we've already sudo'd to RUNNER_USER
+    # Don't continue if we've already su'd to RUNNER_USER
     if ([ "$RUNNER_USER" ] && [ "x$WHOAMI" != "x$RUNNER_USER" ]); then
         if [ -w $RUN_DIR ]; then
             mkdir -p $PID_DIR
@@ -161,12 +161,12 @@
     # Validate that the user running the script is the owner of the
     # RUN_DIR.
     if ([ "$RUNNER_USER" ] && [ "x$WHOAMI" != "x$RUNNER_USER" ]); then
-        type sudo > /dev/null 2>&1
+        type su > /dev/null 2>&1
         if [ "$?" -ne 0 ]; then
-            echoerr "sudo doesn't appear to be installed and your EUID isn't $RUNNER_USER" 1>&2
+            echoerr "su doesn't appear to be installed and your EUID isn't $RUNNER_USER" 1>&2
             exit 1
         fi
-        exec sudo -H -u $RUNNER_USER -i $RUNNER_SCRIPT_DIR/$RUNNER_SCRIPT $@
+	exec su - $RUNNER_USER -c "$RUNNER_SCRIPT_DIR/$RUNNER_SCRIPT $@"
     fi
 }

