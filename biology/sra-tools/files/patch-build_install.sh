--- build/install.sh.orig	2026-05-12 20:23:33 UTC
+++ build/install.sh
@@ -49,8 +49,12 @@ if [ "$EUID" -eq 0 ]; then
         $SCRIPT_DIR/install-kfg.sh vdb-copy.kfg $SRC_DIR_COPY $KONFIG_DIR_ROOT $KFGSUMS_FILE
     fi
 
-PROFILE_FILE=/etc/profile.d/sra-tools
+    # We don't need these in FreeBSD ports, since the programs install
+    # into the default PATH and ldconfig points to the libraries.
+    if false; then
 
+    PROFILE_FILE=/etc/profile.d/sra-tools
+
     echo "Updating ${PROFILE_FILE}.sh"
     printf \
 "#version ${VERSION}\n"\
@@ -71,6 +75,7 @@ PROFILE_FILE=/etc/profile.d/sra-tools
 "setenv NGS_LIBDIR ${LIBDIR}\n" \
         >${PROFILE_FILE}.csh && chmod 644 ${PROFILE_FILE}.csh
 
+    endif
 else
 
     $SCRIPT_DIR/install-kfg.sh default.kfg  $SRC_DIR      $KONFIG_DIR $SRC_DIR/kfgsums
