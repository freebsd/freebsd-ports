--- features/org.eclipse.equinox.executable/library/gtk/build.sh.orig	2007-06-26 04:57:45.000000000 +0900
+++ features/org.eclipse.equinox.executable/library/gtk/build.sh	2007-08-25 14:35:16.000000000 +0900
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
