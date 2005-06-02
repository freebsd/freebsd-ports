--- config/install.sh.orig	Wed May 18 18:59:22 2005
+++ config/install.sh	Mon May 30 19:46:41 2005
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
 
 
@@ -308,7 +332,12 @@
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
@@ -317,6 +346,11 @@
     vsay $this: Run-time system already exists.
 else
     "$CONFIGDIR"/unpack "$ROOT" runtime
+    [ -n "$MLRUNTIMEPATCHES" ] && \
+    for p in $MLRUNTIMEPATCHES
+    do
+	do_patch $p
+    done
     cd "$SRCDIR"/runtime/objs
     echo $this: Compiling the run-time system.
     $MAKE -f mk.$ARCH-$OPSYS $EXTRA_DEFS
@@ -325,7 +359,7 @@
 	if [ -f runx.$ARCH-$OPSYS ]; then
 	    mv runx.$ARCH-$OPSYS "$RUNDIR"
 	fi
-	$MAKE MAKE=$MAKE clean
+	[ "$MLNORUNTIMECLEAN" ] || $MAKE MAKE=$MAKE clean
     else
 	complain "$this: !!! Run-time system build failed for some reason."
     fi
@@ -351,7 +385,7 @@
 	complain "$this !!! Unable to re-create heap image (sml.$HEAP_SUFFIX)."
     fi
 else
-    "$CONFIGDIR"/unpack "$ROOT" "$BOOT_ARCHIVE"
+    [ -n "$RECOMPILEDIR" ] || "$CONFIGDIR"/unpack "$ROOT" "$BOOT_ARCHIVE"
 
     fish "$ROOT"/"$BOOT_FILES"/basis.cm
 
@@ -422,5 +456,12 @@
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
