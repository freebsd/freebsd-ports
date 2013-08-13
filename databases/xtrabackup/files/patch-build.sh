--- utils/build.sh	2013-08-01 15:26:37.000000000 +0200
+++ utils/build.sh	2013-08-13 08:52:57.520334456 +0200
@@ -289,6 +289,7 @@
                 -DWITH_EXTRA_CHARSETS=all \
                 -DWITH_EMBEDDED_SERVER=1 \
                 -DENABLE_DTRACE=OFF $extra_config_55plus"
+        export LIBS=-lcrypt
         build_all $type
         ;;
 
