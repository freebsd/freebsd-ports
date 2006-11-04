--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh.orig	Thu Jun 29 19:22:14 2006
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh	Wed Sep  6 15:55:41 2006
@@ -31,6 +31,10 @@
 		SWT_OS=solaris
 		MAKEFILE=make_solaris.mak
 		;;
+	"FreeBSD")
+                SWT_OS=freebsd
+                MAKEFILE=make_freebsd.mak
+               ;;
 	*)
 		SWT_OS=`uname -s | tr -s '[:upper:]' '[:lower:]'`
 		MAKEFILE=make_linux.mak
@@ -61,7 +65,7 @@
 esac
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'amd64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' ]; then
 	SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
 	export SWT_PTR_CFLAGS
 	if [ -d /lib64 ]; then
@@ -70,32 +74,38 @@
 	fi
 fi
 
-if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
-	echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
-	MAKE_GNOME=make_gnome
-else
-	echo "libgnome-2.0 and libgnomeui-2.0 not found:"
-	echo "    *** SWT Program support for GNOME will not be compiled."
+if [ ${MAKE_GNOME} != "" ]; then
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
+if [ ${MAKE_CAIRO} != "" ]; then
+	if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
+		echo "Cairo found, compiling SWT support for the cairo graphics library."
+		MAKE_CAIRO=make_cairo
+	else
+		echo "Cairo not found:"
+		echo "    *** Advanced graphics support using cairo will not be compiled."
+	fi
 fi
 
-if [ -z "${GECKO_INCLUDES}" -a -z "${GECKO_LIBS}" ]; then
-	if [ x`pkg-config --exists mozilla-xpcom && echo YES` = "xYES" ]; then
-		GECKO_INCLUDES=`pkg-config --cflags mozilla-xpcom`
-		GECKO_LIBS=`pkg-config --libs mozilla-xpcom`
-		export GECKO_INCLUDES
-		export GECKO_LIBS
-		MAKE_MOZILLA=make_mozilla
-	else
-		echo "Mozilla/XPCOM libraries not found:"
-		echo "    *** Mozilla embedding support will not be compiled."
+if [ ${MAKE_MOZILLA} != "" ]; then
+	if [ -z "${GECKO_INCLUDES}" -a -z "${GECKO_LIBS}" ]; then
+		if [ x`pkg-config --exists mozilla-xpcom && echo YES` = "xYES" ]; then
+			GECKO_INCLUDES=`pkg-config --cflags mozilla-xpcom`
+			GECKO_LIBS=`pkg-config --libs mozilla-xpcom`
+			export GECKO_INCLUDES
+			export GECKO_LIBS
+			MAKE_MOZILLA=make_mozilla
+		else
+			echo "Mozilla/XPCOM libraries not found:"
+			echo "    *** Mozilla embedding support will not be compiled."
+		fi
 	fi
 fi
 
