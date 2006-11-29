--- config/install.sh.orig	Thu Nov  2 22:23:22 2006
+++ config/install.sh	Sun Nov 19 23:51:03 2006
@@ -18,6 +18,8 @@
     nolib=false
 fi
 
+[ -n "$RECOMPILEDIR" ] && echo "RECOMPILEDIR=$RECOMPILEDIR"
+
 if [ x${INSTALL_QUIETLY} = xtrue ] ; then
     export CM_VERBOSE
     CM_VERBOSE=false
@@ -38,6 +40,28 @@
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
 
 
@@ -307,7 +331,12 @@
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
@@ -316,6 +345,11 @@
     vsay $this: Run-time system already exists.
 else
     "$CONFIGDIR"/unpack "$ROOT" runtime
+    [ -n "$MLRUNTIMEPATCHES" ] && \
+    for p in $MLRUNTIMEPATCHES
+    do
+	do_patch $p
+    done
     cd "$BASEDIR"/runtime/objs
     echo $this: Compiling the run-time system.
     $MAKE -f mk.$ARCH-$OPSYS $EXTRA_DEFS
@@ -330,7 +364,7 @@
 	if [ -f run.$ARCH-$OPSYS.a ]; then
 	    mv run.$ARCH-$OPSYS.a "$RUNDIR"
 	fi
-	$MAKE MAKE=$MAKE clean
+	[ "$MLNORUNTIMECLEAN" ] || $MAKE MAKE=$MAKE clean
     else
 	complain "$this: !!! Run-time system build failed for some reason."
     fi
@@ -356,7 +390,7 @@
 	complain "$this !!! Unable to re-create heap image (sml.$HEAP_SUFFIX)."
     fi
 else
-    "$CONFIGDIR"/unpack "$ROOT" "$BOOT_ARCHIVE"
+    [ -n "$RECOMPILEDIR" ] || "$CONFIGDIR"/unpack "$ROOT" "$BOOT_ARCHIVE"
 
     fish "$ROOT"/"$BOOT_FILES"/smlnj/basis
 
@@ -427,5 +461,12 @@
 	complain "$this: !!! Installation of libraries and programs failed."
     fi
 fi
+
+# apply source patches
+[ -n "$MLSOURCEPATCHES" ] && \
+for p in $MLSOURCEPATCHES
+do
+	do_patch $p
+done
 
 exit 0
