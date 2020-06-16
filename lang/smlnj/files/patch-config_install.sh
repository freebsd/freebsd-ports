--- config/install.sh.orig	2019-11-23 16:06:59 UTC
+++ config/install.sh
@@ -56,11 +56,36 @@ if [ x"$SIZE_OPT" = x ] ; then
     SIZE_OPT="-"$DEFAULT_SIZE
 fi
 
+[ -n "$RECOMPILEDIR" ] && echo "RECOMPILEDIR=$RECOMPILEDIR"
+
 if [ x${INSTALL_QUIETLY} = xtrue ] ; then
     export CM_VERBOSE
     CM_VERBOSE=false
 fi
 
+#
+# do_patch patch-file
+# apply a patch file
+#
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
 vsay() {
     if [ x${INSTALL_DEBUG} = xtrue ] ; then
 	echo "$@"
@@ -128,7 +153,28 @@ trap 'cd "$ROOT"; rm -f $tmpfiles' 0 1 2 3 15
 # Especially important is CM_PATHCONFIG.
 #
 export CM_PATHCONFIG
-CM_PATHCONFIG=$LIBDIR/pathconfig
+if [ -n "$STAGEDIR" -a -n "$MLLIB" ]
+then
+	# The final CM_PATHCONFIG file should not yet exist during
+	# staging, but still it has to be set in the environment when
+	# creating the (final) compiler heap. This way it becomes the
+	# the default pathconfig for the (final) heap.
+	# Therefore we will use the secondary pathconfig environment
+	# variable CM_LOCAL_PATHCONFIG to point to the (existing;)
+	# pathconfig in ROOT. This enables $smlnj/installer.cm
+	# to operate within STAGEDIR (using the final heap) below.
+	CM_PATHCONFIG=$MLLIB/pathconfig
+	if [ -r $CM_PATHCONFIG ]
+	then
+		vsay "$this: !!! Staging conflicts with an existing installation!"
+		complain "$this: !!! Make $CM_PATHCONFIG unreadable and try again!"
+	fi
+	CM_PATHCONFIG_STAGE=$STAGEDIR$CM_PATHCONFIG
+	CM_LOCAL_PATHCONFIG=$CM_PATHCONFIG_STAGE
+else
+	CM_PATHCONFIG=$LIBDIR/pathconfig
+	CM_PATHCONFIG_STAGE=$CM_PATHCONFIG
+fi
 #
 # the release version that we are installing
 #
@@ -403,7 +449,12 @@ esac
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
@@ -412,9 +463,15 @@ if [ -x "$RUNDIR"/run.$ARCH-$OPSYS ]; then
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
-    $MAKE -f $RT_MAKEFILE $EXTRA_DEFS
+    echo "$MAKE -f $RT_MAKEFILE $EXTRA_DEFS AS=\"$AS\" ASFLAGS=\"$ASFLAGS\" CFLAGS=\"$CFLAGS\" LDFLAGS=\"$LDFLAGS\""
+    $MAKE -f $RT_MAKEFILE $EXTRA_DEFS AS="$AS" ASFLAGS="$ASFLAGS" CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS"
     if [ -x run.$ARCH-$OPSYS ]; then
 	mv run.$ARCH-$OPSYS "$RUNDIR"
 	if [ -f runx.$ARCH-$OPSYS ]; then
@@ -426,7 +483,7 @@ else
 	if [ -f run.$ARCH-$OPSYS.a ]; then
 	    mv run.$ARCH-$OPSYS.a "$RUNDIR"
 	fi
-	$MAKE MAKE=$MAKE clean
+	[ "$MLNORUNTIMECLEAN" ] || $MAKE MAKE=$MAKE clean
     else
 	complain "$this: !!! Run-time system build failed for some reason."
     fi
@@ -452,7 +509,7 @@ if [ -r "$HEAPDIR"/sml.$HEAP_SUFFIX ]; then
 	complain "$this !!! Unable to re-create heap image (sml.$HEAP_SUFFIX)."
     fi
 else
-    "$CONFIGDIR"/unpack "$ROOT" "$BOOT_ARCHIVE"
+    [ -n "$RECOMPILEDIR" ] || "$CONFIGDIR"/unpack "$ROOT" "$BOOT_ARCHIVE"
 
     fish "$ROOT"/"$BOOT_FILES"/smlnj/basis
 
@@ -487,7 +544,7 @@ else
 	    cd "$ROOT"/"$BOOT_FILES"
 	    for anchor in * ; do
 		if [ -d $anchor ] ; then
-		    echo $anchor $anchor >>$CM_PATHCONFIG
+		    echo $anchor $anchor >>$CM_PATHCONFIG_STAGE
 		    move $anchor "$LIBDIR"/$anchor
 		fi
 	    done
@@ -510,6 +567,18 @@ installdriver _ml-build ml-build
 
 cd "$ROOT"
 
+# apply source patches for standard targets
+[ -n "$MLSTANDARDPATCHDIRS" ] && \
+for d in $MLSTANDARDPATCHDIRS
+do
+	"$CONFIGDIR"/unpack "$ROOT" "$d"
+done
+[ -n "$MLSTANDARDPATCHES" ] && \
+for p in $MLSTANDARDPATCHES
+do
+	do_patch $p
+done
+
 #
 # Now do all the rest using the precompiled installer
 # (see base/system/smlnj/installer for details)
@@ -519,6 +588,12 @@ if [ $nolib = false ] ; then
     export ROOT INSTALLDIR CONFIGDIR BINDIR
     CM_TOLERATE_TOOL_FAILURES=true
     export CM_TOLERATE_TOOL_FAILURES
+    # smlnj/installer/nix-install.sml (re)sets CM_LOCAL_PATHCONFIG
+    # to /dev/null in the buildcmd that it uses to invoke the builds.
+    # So the build process needs a working CM_PATHCONFIG. This is NOT
+    # propagated to the resulting heaps because the heaps generated
+    # in this stage don't contain the compiler.
+    [ -z "$STAGEDIR" ] || CM_PATHCONFIG=$CM_LOCAL_PATHCONFIG
     if "$BINDIR"/sml $SIZE_OPT -m \$smlnj/installer.cm
     then
 	vsay $this: Installation complete.
@@ -526,5 +601,20 @@ if [ $nolib = false ] ; then
 	complain "$this: !!! Installation of libraries and programs failed."
     fi
 fi
+
+# Finish staging by removing the $STAGEDIR prefix from the driver scripts.
+if [ -n "$STAGEDIR" ]
+then
+	find $BINDIR -type f -perm -1 | \
+	xargs fgrep -l "$STAGEDIR" | \
+	xargs sed -i "" -e 's%'"$STAGEDIR"'%%g'
+fi
+
+# apply all source patches
+[ -n "$MLSOURCEPATCHES" ] && \
+for p in $MLSOURCEPATCHES
+do
+	do_patch $p
+done
 
 exit 0
