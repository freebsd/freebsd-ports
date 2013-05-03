--- configure_tests.sh.orig	2013-05-02 12:43:23.000000000 +0400
+++ configure_tests.sh	2013-05-02 12:44:18.000000000 +0400
@@ -1111,7 +1111,7 @@ fi
 if [ -n "$PO" ] && [ $PO -gt 0 ]; then
   pos_dir="`ls $ROOT_DIR/po/*.po 2> /dev/null`"
   LING="`echo $pos_dir | sed s%$ROOT_DIR/%%g`"
-  LINGUAS="`echo $pos_dir | sed s%\.po%%g | sed s%$ROOT_DIR/%%g`"
+  LINGUAS="`echo $pos_dir | sed s%$ROOT_DIR/po/%%g | sed s%\.po%%g`"
   echo "LINGUAS = $LINGUAS" >> $CONF
   echo_="translations available: $LINGUAS"; echo "$echo_" >> $CONF_LOG; test -n "$ECHO" && $ECHO "$echo_"
   echo "LING = $LING" >> $CONF
