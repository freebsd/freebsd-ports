--- bin/clion.sh.orig	2026-03-19 14:42:21 UTC
+++ bin/clion.sh
@@ -91,7 +91,7 @@ fi
 # ---------------------------------------------------------------------
 # Collect JVM options and IDE properties.
 # ---------------------------------------------------------------------
-IDE_PROPERTIES_PROPERTY=""
+IDE_PROPERTIES_PROPERTY="-Didea.suppressed.plugins.set.selector=classic"
 # shellcheck disable=SC2154
 if [ -n "$CLION_PROPERTIES" ]; then
   IDE_PROPERTIES_PROPERTY="-Didea.properties.file=$CLION_PROPERTIES"
