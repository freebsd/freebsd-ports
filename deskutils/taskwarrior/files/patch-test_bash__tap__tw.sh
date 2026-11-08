--- test/bash_tap_tw.sh.orig	2025-08-16 19:02:31 UTC
+++ test/bash_tap_tw.sh
@@ -18,6 +18,14 @@
 # Subject to the MIT License. See LICENSE file or https://opensource.org/licenses
 # Copyright (c) 2015 - 2021, Wilhelm Schürmann
 
+# FreeBSD ports: PREFIX is not populated when "make test" runs, so the
+# built-in "include default.theme" cannot be resolved through the
+# compiled-in search path.  Remember the location of the rc files while
+# the script is still sourced from the original directory (bash_tap.sh
+# changes to a temporary sandbox before setup_taskrc is run) and copy
+# them next to the test taskrc later.
+_TW_RC_DIR="$(cd "$(dirname "$0")/../doc/rc" 2>/dev/null && pwd)"
+
 function setup_taskrc {
     # Configuration
     for i in taskchampion.sqlite3 taskrc; do
@@ -27,6 +35,10 @@ function setup_taskrc {
 
     export TASKDATA=.
 
+    if [ -n "${_TW_RC_DIR}" ]; then
+        cp "${_TW_RC_DIR}/"* .
+    fi
+
     echo 'confirmation=off'               > taskrc
     echo 'color.debug=rgb025'             >> taskrc
     echo 'color.header=rgb025'            >> taskrc
