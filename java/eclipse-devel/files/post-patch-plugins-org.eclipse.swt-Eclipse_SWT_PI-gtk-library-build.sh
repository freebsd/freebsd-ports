--- gtk/library/build.sh.orig	2008-08-02 20:48:26.157201172 -0400
+++ gtk/library/build.sh	2008-08-02 22:49:45.246241822 -0400
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
@@ -74,23 +78,28 @@
 	fi
 fi
 
-if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
-	echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
-	MAKE_GNOME=make_gnome
-else
-	echo "libgnome-2.0 and libgnomeui-2.0 not found:"
-	echo "    *** SWT Program support for GNOME will not be compiled."
+if [ x${MAKE_GNOME} = "xmake_gnome" ]; then
+	if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
+		echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
+		MAKE_GNOME=make_gnome
+	else
+		echo "libgnome-2.0 and libgnomeui-2.0 not found:"
+		echo "    *** SWT Program support for GNOME will not be compiled."
+	fi
 fi
 
-if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
-	echo "Cairo found, compiling SWT support for the cairo graphics library."
-	MAKE_CAIRO=make_cairo
-else
-	echo "Cairo not found:"
-	echo "    *** Advanced graphics support using cairo will not be compiled."
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
+	if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
+		echo "Cairo found, compiling SWT support for the cairo graphics library."
+		MAKE_CAIRO=make_cairo
+	else
+		echo "Cairo not found:"
+		echo "    *** Advanced graphics support using cairo will not be compiled."
+	fi
 fi
 
-if [ -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" ]; then
+if [ x${MAKE_MOZILLA} = "xmake_mozilla" ]; then
+    if [ -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" ]; then
 	if [ x`pkg-config --exists mozilla-xpcom && echo YES` = "xYES" ]; then
 		MOZILLA_INCLUDES=`pkg-config --cflags mozilla-xpcom`
 		MOZILLA_LIBS=`pkg-config --libs mozilla-xpcom`
@@ -113,6 +122,7 @@
 		echo "None of the following libraries were found:  Mozilla/XPCOM, Firefox/XPCOM, or XULRunner/XPCOM"
 		echo "    *** Mozilla embedding support will not be compiled."
 	fi
+    fi
 fi
 
 # Find AWT if available
