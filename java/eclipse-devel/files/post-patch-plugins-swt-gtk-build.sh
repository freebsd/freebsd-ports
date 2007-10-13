--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh.orig	2007-06-26 04:57:13.000000000 +0900
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh	2007-10-07 14:10:27.000000000 +0900
@@ -10,6 +10,9 @@
 #     IBM Corporation - initial API and implementation
 #     Kevin Cornell (Rational Software Corporation)
 #     Tom Tromey (Red Hat, Inc.)
+#
+# This is Eclipse SWT PI/gtk/library/build.xml
+#
 #*******************************************************************************
 
 cd `dirname $0`
@@ -26,6 +29,7 @@
 if [ "${OS}" = "" ]; then
 	OS=`uname -s`
 fi
+
 case $OS in
 	"SunOS")
 		SWT_OS=solaris
@@ -50,6 +54,10 @@
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
@@ -65,32 +73,37 @@
 esac
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 's390x' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'amd64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 's390x' ]; then
 	SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
 	export SWT_PTR_CFLAGS
 	if [ -d /lib64 ]; then
-		XLIB64=-L/usr/X11R6/lib64
+		XLIB64=-L/usr/local/lib64
 		export XLIB64
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
@@ -107,6 +120,7 @@
 		echo "Mozilla/XPCOM or Firefox/XPCOM libraries not found:"
 		echo "    *** Mozilla embedding support will not be compiled."
 	fi
+    fi
 fi
 
 # Find AWT if available
