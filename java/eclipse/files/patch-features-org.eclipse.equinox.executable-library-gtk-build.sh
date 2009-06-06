--- features/org.eclipse.equinox.executable/library/gtk/build.sh.orig	2009-02-15 20:00:26.335076358 -0500
+++ features/org.eclipse.equinox.executable/library/gtk/build.sh	2009-02-15 19:58:28.194586994 -0500
@@ -53,6 +53,7 @@
 	"Linux")
 		makefile="make_linux.mak"
 		defaultOS="linux"
+		MAKE=make
 		case $MODEL in
 			"x86_64")
 				defaultOSArch="x86_64"
@@ -94,9 +95,28 @@
 				;;
 		esac
 		;;
+	"FreeBSD")
+		makefile="make_freebsd.mak"
+		defaultOS="freebsd"
+		MAKE=gmake
+		javaHome="$JAVA_HOME"
+		defaultJava=DEFAULT_JAVA_EXEC
+		case $MODEL in
+			"amd64")
+				defaultOSArch="x86_64"
+				;;
+			i?86)
+				defaultOSArch="x86"
+				;;
+			*)
+				echo "*** Unknown MODEL <${MODEL}>"
+				;;
+		esac
+		;;
 	"SunOS")
 		makefile="make_solaris.mak"
 		defaultOS="solaris"
+		MAKE=make
 		javaHome="/usr/jdk/jdk1.5.0_01"
 		OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
 		#PATH=/usr/ccs/bin:/opt/SUNWspro/bin:$PATH
@@ -154,7 +174,7 @@
 JAVA_HOME=$javaHome
 DEFAULT_JAVA=$defaultJava
 
-LIBRARY_DIR="../../../org.eclipse.equinox.launcher/fragments/org.eclipse.equinox.launcher.$defaultWS.$defaultOS.$defaultOSArch"
+LIBRARY_DIR="../../../../plugins/org.eclipse.equinox.launcher.$defaultWS.$defaultOS.$defaultOSArch"
 OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
 
 export OUTPUT_DIR PROGRAM_OUTPUT DEFAULT_OS DEFAULT_OS_ARCH DEFAULT_WS JAVA_HOME DEFAULT_JAVA LIBRARY_DIR
@@ -162,13 +182,13 @@
 # If the OS is supported (a makefile exists)
 if [ "$makefile" != "" ]; then
 	if [ "$extraArgs" != "" ]; then
-		make -f $makefile $extraArgs
+		${MAKE} -f $makefile $extraArgs
 	else
 		echo "Building $OS launcher. Defaults: -os $DEFAULT_OS -arch $DEFAULT_OS_ARCH -ws $DEFAULT_WS"
-		make -f $makefile clean
+		${MAKE} -f $makefile clean
 		case x$CC in
-		  x*gcc*) make -f $makefile all PICFLAG=-fpic ;;
-		  *)      make -f $makefile all ;;
+		  x*gcc*) ${MAKE} -f $makefile all PICFLAG=-fpic ;;
+		  *)      ${MAKE} -f $makefile all ;;
 		esac
 	fi
 else
