--- gtk/library/build.sh.orig	2008-09-11 21:18:02.725614374 -0400
+++ gtk/library/build.sh	2008-09-11 21:18:07.455632295 -0400
@@ -50,6 +50,10 @@
 	fi
 fi
 case $MODEL in
+	"amd64")
+		SWT_ARCH=x86_64
+		AWT_ARCH=amd64
+		;;
 	"x86_64")
 		SWT_ARCH=x86_64
 		AWT_ARCH=amd64
@@ -65,7 +69,7 @@
 esac
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 's390x' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'amd64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 's390x' ]; then
 	SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
 	export SWT_PTR_CFLAGS
 	if [ -d /lib64 ]; then
@@ -74,47 +78,44 @@
 	fi
 fi
 
-if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
-	echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
-	MAKE_GNOME=make_gnome
-else
-	echo "libgnome-2.0 and libgnomeui-2.0 not found:"
-	echo "    *** SWT Program support for GNOME will not be compiled."
-fi
-
-if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
-	echo "Cairo found, compiling SWT support for the cairo graphics library."
-	MAKE_CAIRO=make_cairo
-else
-	echo "Cairo not found:"
-	echo "    *** Advanced graphics support using cairo will not be compiled."
+if [ x${MAKE_GNOME} = "xmake_gnome" ]; then
+	if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
+		echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
+		_MAKE_GNOME=make_gnome
+	else
+		echo "libgnome-2.0 and libgnomeui-2.0 not found:"
+		echo "    *** SWT Program support for GNOME will not be compiled."
+	fi
 fi
 
-if [ -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" ]; then
-	if [ x`pkg-config --exists mozilla-xpcom && echo YES` = "xYES" ]; then
-		MOZILLA_INCLUDES=`pkg-config --cflags mozilla-xpcom`
-		MOZILLA_LIBS=`pkg-config --libs mozilla-xpcom`
-		export MOZILLA_INCLUDES
-		export MOZILLA_LIBS
-		MAKE_MOZILLA=make_mozilla
-	elif [ x`pkg-config --exists firefox-xpcom && echo YES` = "xYES" ]; then
-		MOZILLA_INCLUDES=`pkg-config --cflags firefox-xpcom`
-		MOZILLA_LIBS=`pkg-config --libs firefox-xpcom`
-		export MOZILLA_INCLUDES
-		export MOZILLA_LIBS
-		MAKE_MOZILLA=make_mozilla
-	elif [ x`pkg-config --exists libxul && echo YES` = "xYES" ]; then
-		MOZILLA_INCLUDES=`pkg-config --cflags libxul`
-		MOZILLA_LIBS=`pkg-config --libs libxul`
-		export MOZILLA_INCLUDES
-		export MOZILLA_LIBS
-		MAKE_MOZILLA=make_mozilla
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
+	if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
+		echo "Cairo found, compiling SWT support for the cairo graphics library."
+		_MAKE_CAIRO=make_cairo
 	else
-		echo "None of the following libraries were found:  Mozilla/XPCOM, Firefox/XPCOM, or XULRunner/XPCOM"
-		echo "    *** Mozilla embedding support will not be compiled."
+		echo "Cairo not found:"
+		echo "    *** Advanced graphics support using cairo will not be compiled."
 	fi
 fi
 
+if [ x${MAKE_MOZILLA} = "xmake_mozilla" ]; then
+    if [ -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" ]; then
+	case ${BROWSER} in
+		"firefox" | "mozilla" | "seamonkey" | "xulrunner")
+			MOZILLA_INCLUDES=`pkg-config --cflags ${BROWSER}-xpcom`
+			MOZILLA_LIBS=`pkg-config --libs ${BROWSER}-xpcom`
+			export MOZILLA_INCLUDES
+			export MOZILLA_LIBS
+			_MAKE_MOZILLA=make_mozilla
+			;;
+		*)
+			echo "None of the following libraries were found:  Mozilla/XPCOM, Firefox/XPCOM, or XULRunner/XPCOM"
+			echo "    *** Mozilla embedding support will not be compiled."
+			;;
+	esac
+    fi
+fi
+
 # Find AWT if available
 if [ -z "${AWT_LIB_PATH}" ]; then
 	if [ -d ${JAVA_HOME}/jre/lib/${AWT_ARCH} ]; then
@@ -142,5 +143,5 @@
 if [ "x${1}" = "xclean" ]; then
 	make -f $MAKEFILE clean
 else
-	make -f $MAKEFILE all $MAKE_GNOME $MAKE_CAIRO $MAKE_AWT $MAKE_MOZILLA ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9}
+	make -f $MAKEFILE all $_MAKE_GNOME $_MAKE_CAIRO $MAKE_AWT $_MAKE_MOZILLA ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9}
 fi
