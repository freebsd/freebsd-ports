--- features/org.eclipse.platform.launchers/library/motif/build.sh~	Sat Feb 19 12:13:49 2005
+++ features/org.eclipse.platform.launchers/library/motif/build.sh	Sun Mar 20 15:27:04 2005
@@ -55,6 +55,15 @@
 		MOTIF_HOME=/bluebird/teamswt/swt-builddir/motif21		
 		OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
 		;;
+	"FreeBSD")
+		makefile="make_freebsd.mak"
+		defaultOS="freebsd"
+		defaultOSArch="x86"
+		defaultWS="motif"
+		X11_HOME=$X11BASE
+		MOTIF_HOME=$X11BASE
+		OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
+		;;
 	"SunOS")
 		makefile="make_solaris.mak"
 		defaultOS="solaris"
@@ -122,11 +131,11 @@
 # If the OS is supported (a makefile exists)
 if [ "$makefile" != "" ]; then
 	if [ "$extraArgs" != "" ]; then
-		make -f $makefile $extraArgs
+		gmake -f $makefile $extraArgs
 	else
 		echo "Building $OS launcher. Defaults: -os $DEFAULT_OS -arch $DEFAULT_OS_ARCH -ws $DEFAULT_WS"
-		make -f $makefile clean
-		make -f $makefile all
+		gmake -f $makefile clean
+		gmake -f $makefile all
 	fi
 else
 	echo "Unknown OS ($OS) -- build aborted"
