--- gtk/library/build.sh.orig	2009-02-15 12:44:50.966087957 -0500
+++ gtk/library/build.sh	2009-02-15 12:45:01.414490300 -0500
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
@@ -74,45 +78,43 @@
 	fi
 fi
 
-if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
+if [ x${MAKE_GNOME} = "xmake_gnome" -a x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
 	echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
-	MAKE_GNOME=make_gnome
+	INTERNAL_MAKE_GNOME=make_gnome
 else
 	echo "libgnome-2.0 and libgnomeui-2.0 not found:"
 	echo "    *** SWT Program support for GNOME will not be compiled."
 fi
 
-if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
+if [ x${MAKE_CAIRO} = "xmake_cairo" -a x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
 	echo "Cairo found, compiling SWT support for the cairo graphics library."
-	MAKE_CAIRO=make_cairo
+	INTERNAL_MAKE_CAIRO=make_cairo
 else
 	echo "Cairo not found:"
 	echo "    *** Advanced graphics support using cairo will not be compiled."
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
-	else
-		echo "None of the following libraries were found:  Mozilla/XPCOM, Firefox/XPCOM, or XULRunner/XPCOM"
-		echo "    *** Mozilla embedding support will not be compiled."
-	fi
+if [ x${MAKE_MOZILLA} = "xmake_mozilla" -a -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" ]; then
+	case ${BROWSER} in
+		"firefox" | "mozilla" | "seamonkey" | "xulrunner")
+			MOZILLA_INCLUDES=`pkg-config --cflags ${BROWSER}-xpcom`
+			MOZILLA_LIBS=`pkg-config --libs ${BROWSER}-xpcom`
+			export MOZILLA_INCLUDES
+			export MOZILLA_LIBS
+			INTERNAL_MAKE_MOZILLA=make_mozilla
+			;;
+		"libxul")
+			MOZILLA_INCLUDES=`pkg-config --cflags ${BROWSER}`
+			MOZILLA_LIBS=`pkg-config --libs ${BROWSER}`
+			export MOZILLA_INCLUDES
+			export MOZILLA_LIBS
+			INTERNAL_MAKE_MOZILLA=make_mozilla
+			;;
+		*)
+			echo "None of the following libraries were found:  Mozilla/XPCOM, Firefox/XPCOM, or XULRunner/XPCOM"
+			echo "    *** Mozilla embedding support will not be compiled."
+		;;
+	esac
 fi
 
 # Find AWT if available
@@ -142,5 +144,5 @@
 if [ "x${1}" = "xclean" ]; then
 	make -f $MAKEFILE clean
 else
-	make -f $MAKEFILE all $MAKE_GNOME $MAKE_CAIRO $MAKE_AWT $MAKE_MOZILLA ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9}
+	make -f $MAKEFILE all $INTERNAL_MAKE_GNOME $INTERNAL_MAKE_CAIRO $MAKE_AWT $INTERNAL_MAKE_MOZILLA ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9}
 fi
