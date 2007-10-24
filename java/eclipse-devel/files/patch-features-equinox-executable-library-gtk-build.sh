--- features/org.eclipse.equinox.executable/library/gtk/build.sh.orig	2007-09-22 01:59:40.000000000 +0900
+++ features/org.eclipse.equinox.executable/library/gtk/build.sh	2007-10-20 18:57:55.000000000 +0900
@@ -10,6 +10,9 @@
 #     IBM Corporation - initial API and implementation
 #     Kevin Cornell (Rational Software Corporation)
 # Martin Oberhuber (Wind River) - [176805] Support building with gcc and debug
+#
+#   This is from "features/org.eclipse.equinox.executable/library/gtk/build.sh"
+#
 #*******************************************************************************
 #
 # Usage: sh build.sh [<optional switches>] [clean]
@@ -50,6 +53,25 @@
 fi
 
 case $OS in
+	"FreeBSD")
+		makefile="make_freebsd.mak"
+		defaultOS="freebsd"
+		case $MODEL in
+			"amd64")
+				defaultOSArch="amd64"
+				defaultJava=DEFAULT_JAVA_EXEC
+				OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
+				;;
+			i?86)
+				defaultOSArch="x86"
+				defaultJava=DEFAULT_JAVA_EXEC
+				OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
+				;;
+			*)
+				echo "*** Unknown MODEL <${MODEL}>"
+				;;
+		esac
+		;;
 	"Linux")
 		makefile="make_linux.mak"
 		defaultOS="linux"
@@ -148,7 +170,6 @@
 DEFAULT_OS="$defaultOS"
 DEFAULT_OS_ARCH="$defaultOSArch"
 DEFAULT_WS="$defaultWS"
-JAVA_HOME=$javaHome
 DEFAULT_JAVA=$defaultJava
 
 export OUTPUT_DIR PROGRAM_OUTPUT DEFAULT_OS DEFAULT_OS_ARCH DEFAULT_WS JAVA_HOME DEFAULT_JAVA
@@ -156,13 +177,13 @@
 # If the OS is supported (a makefile exists)
 if [ "$makefile" != "" ]; then
 	if [ "$extraArgs" != "" ]; then
-		make -f $makefile $extraArgs
+		gmake -f $makefile $extraArgs
 	else
 		echo "Building $OS launcher. Defaults: -os $DEFAULT_OS -arch $DEFAULT_OS_ARCH -ws $DEFAULT_WS"
-		make -f $makefile clean
+		gmake -f $makefile clean
 		case x$CC in
-		  x*gcc*) make -f $makefile all PICFLAG=-fpic ;;
-		  *)      make -f $makefile all ;;
+		  x*gcc*) gmake -f $makefile all PICFLAG=-fpic ;;
+		  *)      gmake -f $makefile all ;;
 		esac
 	fi
 else
