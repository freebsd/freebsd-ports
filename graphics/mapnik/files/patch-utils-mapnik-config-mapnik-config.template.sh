--- utils/mapnik-config/mapnik-config.template.sh.orig	2011-10-08 20:02:02.011385698 +0400
+++ utils/mapnik-config/mapnik-config.template.sh	2011-10-08 20:02:21.915390000 +0400
@@ -48,11 +48,11 @@
       ;;
 
     -v)
-      echo $CONFIG_VERSION
+      echo $CONFIG_MAPNIK_VERSION
       ;;
 
     --version)
-      echo $CONFIG_VERSION
+      echo $CONFIG_MAPNIK_VERSION
       ;;
 
     --json)
