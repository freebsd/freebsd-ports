--- src/dest-install.sh.orig	2019-12-02 12:30:03 UTC
+++ src/dest-install.sh
@@ -35,6 +35,7 @@ INSTALL_PREFIX="${1-/usr/local}"
 TMPFILE="/tmp/$0-$$"
 INC=../include
 INCLUDE_DIR="$INSTALL_PREFIX/include/cscout"
+FINAL_INCLUDE_DIR="/usr/local/include/cscout"
 # Permissions for header files
 HMODE=644
 
@@ -52,7 +53,7 @@ install -m $HMODE $TMPFILE "$INCLUDE_DIR/stdc-defs.h"
 
 # Generic C include path specification
 cat <<EOF >$TMPFILE
-#pragma includepath "$INCLUDE_DIR/stdc"
+#pragma includepath "$LATER_INCLUDE_DIR/stdc"
 
 /* Avoid unused include file warnings */
 static void _cscout_dummy2(void) { _cscout_dummy2(); }
@@ -93,7 +94,7 @@ install -m $HMODE $TMPFILE "$INCLUDE_DIR/host-incs.h"
 
 # Perl scripts (keep csmake.pl in the end)
 for f in cswc.pl csmake.pl ; do
-  sed "s|INSTALL_INCLUDE|$INCLUDE_DIR|g" $f >$TMPFILE
+  sed "s|INSTALL_INCLUDE|$LATER_INCLUDE_DIR|g" $f >$TMPFILE
   install $TMPFILE "$INSTALL_PREFIX/bin/$(basename $f .pl)"
 done
 # Install as cscc
