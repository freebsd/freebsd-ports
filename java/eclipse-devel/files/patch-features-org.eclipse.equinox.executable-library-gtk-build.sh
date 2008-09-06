--- features/org.eclipse.equinox.executable/library/gtk/build.sh.orig	2008-08-02 22:30:31.469155349 -0400
+++ features/org.eclipse.equinox.executable/library/gtk/build.sh	2008-08-02 22:32:13.519781895 -0400
@@ -53,6 +53,7 @@
 	"Linux")
 		makefile="make_linux.mak"
 		defaultOS="linux"
+		MAKE=make
 		case $MODEL in
 			"x86_64")
 				defaultOSArch="x86_64"
@@ -93,9 +94,30 @@
 				;;
 		esac
 		;;
+	"FreeBSD")
+		makefile="make_freebsd.mak"
+		defaultOS="freebsd"
+		MAKE=gmake
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
 	"SunOS")
 		makefile="make_solaris.mak"
 		defaultOS="solaris"
+		MAKE=make
 		OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
 		#PATH=/usr/ccs/bin:/opt/SUNWspro/bin:$PATH
 		PATH=/usr/ccs/bin:/export/home/SUNWspro/bin:$PATH
@@ -149,7 +171,7 @@
 DEFAULT_OS="$defaultOS"
 DEFAULT_OS_ARCH="$defaultOSArch"
 DEFAULT_WS="$defaultWS"
-JAVA_HOME=$javaHome
+#JAVA_HOME=$javaHome
 DEFAULT_JAVA=$defaultJava
 
 export OUTPUT_DIR PROGRAM_OUTPUT DEFAULT_OS DEFAULT_OS_ARCH DEFAULT_WS JAVA_HOME DEFAULT_JAVA
@@ -157,13 +179,13 @@
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
