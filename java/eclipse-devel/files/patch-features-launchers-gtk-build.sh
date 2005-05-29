--- features/org.eclipse.platform.launchers/library/gtk/build.sh.orig	Fri Apr  1 13:57:19 2005
+++ features/org.eclipse.platform.launchers/library/gtk/build.sh	Sun Apr  3 11:37:51 2005
@@ -67,6 +67,23 @@
 				;;
 		esac
 		;;
+	"FreeBSD")
+		makefile="make_freebsd.mak"
+		defaultOS="freebsd"
+		case $MODEL in
+			amd64)
+				defaultOSArch="amd64"
+				OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
+				;;
+			i?86)
+				defaultOSArch="x86"
+				OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
+				;;
+			*)
+				echo "*** Unknown MODEL <${MODEL}>"
+				;;
+		esac
+		;;
 	"SunOS")
 		makefile="make_solaris.mak"
 		defaultOS="solaris"
@@ -112,11 +129,11 @@
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
