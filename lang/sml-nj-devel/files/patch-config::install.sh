--- config/install.sh.orig	Thu Oct 28 17:44:01 2004
+++ config/install.sh	Wed Nov  3 13:36:09 2004
@@ -12,6 +12,8 @@
 # Author: Matthias Blume (blume@tti-c.org)
 #
 
+[ -n "$RECOMPILEDIR" ] && echo "RECOMPILEDIR=$RECOMPILEDIR"
+
 if [ x${INSTALL_QUIETLY} = xtrue ] ; then
     export CM_VERBOSE
     CM_VERBOSE=false
@@ -32,6 +34,28 @@
     exit 1
 }
 
+#
+# do_patch patch-file
+# apply a patch file
+do_patch() {
+	patchfile=$FILESDIR/$1
+
+	if [ ! -r $patchfile ]; then
+		echo "$this: !!! patch file $patchfile not found."
+		exit 1;
+	fi
+
+	if [ ! -f $CONFIGDIR/.patch_$1 ]; then
+		$PATCH $PATCH_ARGS < $patchfile || {\
+			echo "$this: !!! patch file $patchfile failed to patch."
+			exit 1;
+		}
+		echo > $CONFIGDIR/.patch_$1
+	else
+		echo "$this: patch $patchfile already installed."
+	fi
+}
+
 this=$0
 
 
@@ -299,7 +323,12 @@
 # the name of the bin files directory
 #
 BOOT_ARCHIVE=boot.$ARCH-unix
-BOOT_FILES=sml.$BOOT_ARCHIVE
+if [ -z "$RECOMPILEDIR" ]
+then
+	BOOT_FILES=sml.$BOOT_ARCHIVE
+else
+	BOOT_FILES=$RECOMPILEDIR/sml.$BOOT_ARCHIVE
+fi
 
 #
 # build the run-time system
@@ -308,12 +337,17 @@
     vsay $this: Run-time system already exists.
 else
     $CONFIGDIR/unpack $ROOT runtime
+    [ -n "$MLRUNTIMEPATCHES" ] && \
+    for p in $MLRUNTIMEPATCHES
+    do
+	do_patch $p
+    done
     cd $SRCDIR/runtime/objs
     echo $this: Compiling the run-time system.
     $MAKE -f mk.$ARCH-$OPSYS $EXTRA_DEFS
     if [ -x run.$ARCH-$OPSYS ]; then
 	mv run.$ARCH-$OPSYS $RUNDIR
-	$MAKE MAKE=$MAKE clean
+	[ "$MLNORUNTIMECLEAN" ] || $MAKE MAKE=$MAKE clean
     else
 	complain "$this: !!! Run-time system build failed for some reason."
     fi
@@ -330,7 +364,7 @@
     export CM_DIR_ARC
     CM_DIR_ARC=$ORIG_CM_DIR_ARC
 else
-    $CONFIGDIR/unpack $ROOT $BOOT_ARCHIVE
+    [ -n "$RECOMPILEDIR" ] || $CONFIGDIR/unpack $ROOT $BOOT_ARCHIVE
 
     fish $ROOT/$BOOT_FILES/basis.cm
 
@@ -399,5 +433,18 @@
 else
     complain "$this: !!! Installation of libraries and programs failed."
 fi
+
+# extract required sources
+[ -n "$MLSOURCEUNPACKTARGETS" ] && \
+for t in $MLSOURCEUNPACKTARGETS
+do
+	$CONFIGDIR/unpack $ROOT $t
+done
+# apply source patches
+[ -n "$MLSOURCEPATCHES" ] && \
+for p in "$MLSOURCEPATCHES"
+do
+	do_patch $p
+done
 
 exit 0
