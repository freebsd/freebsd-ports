--- jd-gui-duo.sh.orig	2026-06-30 08:39:56 UTC
+++ jd-gui-duo.sh
@@ -1,9 +1,8 @@
-#!/bin/bash
-DIR="$(dirname "$0")"
-"$DIR/jre/bin/java" -ea \
+#!/bin/sh
+exec %%JAVA%% -ea \
   --add-opens java.base/java.net=ALL-UNNAMED \
   --add-opens java.desktop/javax.swing.plaf.basic=ALL-UNNAMED \
   --add-opens java.desktop/javax.swing.text=ALL-UNNAMED \
   --add-opens java.prefs/java.util.prefs=ALL-UNNAMED \
   --add-opens java.base/java.lang.ref=ALL-UNNAMED \
-  -cp "$DIR/lib/*" org.jd.gui.App "$@"
+  -cp "%%JAVAJARDIR%%/jd-gui-duo/*" org.jd.gui.App "$@"
