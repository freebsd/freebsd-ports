--- jd-gui-duo.sh.orig	2026-11-24 05:14:09 UTC
+++ jd-gui-duo.sh
@@ -1,9 +1,11 @@
-#!/bin/bash
-DIR="$(dirname "$0")"
-exec "$DIR/jre/bin/java" -ea \
+#!/bin/sh
+if [ -z "${JAVA_HOME}" ]; then
+  JAVA_HOME="%%JAVA_HOME%%"
+fi
+exec "${JAVA_HOME}/bin/java" -ea \
   --add-opens java.base/java.net=ALL-UNNAMED \
   --add-opens java.desktop/javax.swing.plaf.basic=ALL-UNNAMED \
   --add-opens java.desktop/javax.swing.text=ALL-UNNAMED \
   --add-opens java.prefs/java.util.prefs=ALL-UNNAMED \
   --add-opens java.base/java.lang.ref=ALL-UNNAMED \
-  -cp "$DIR/lib/*" org.jd.gui.App "$@"
+  -cp "%%JAVAJARDIR%%/jd-gui-duo/*" org.jd.gui.App "$@"
