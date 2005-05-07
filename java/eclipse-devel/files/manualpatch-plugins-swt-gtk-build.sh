--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh.orig	Fri Apr  1 13:56:58 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh	Sat Apr  9 16:27:29 2005
@@ -110,6 +110,36 @@
 				;;	
 		esac
 		;;
+	"FreeBSD")
+		CC=gcc
+		LD=gcc
+		XTEST_LIB_PATH=$X11BASE/lib
+		KDE_LIB_PATH=$PREFIX/lib
+		KDE_INCLUDE_PATH=$PREFIX/include
+		QT_HOME=$X11BASE
+		GECKO_I=${X11BASE}/include/${BROWSER}
+		GECKO_INCLUDES="-I${GECKO_I} -I${GECKO_I}/nspr -I${GECKO_I}/xpcom -I${GECKO_I}/string -I${GECKO_I}/embed_base -I${GECKO_I}/embedstring"
+		GECKO_L=${X11BASE}/lib/${BROWSER}
+		GECKO_LIBS="-L${GECKO_L} -lxpcom -lnspr4 -lplds4 -lplc4 -lgtkembedmoz"
+		case $MODEL in
+			"amd64")
+				AWT_LIB_PATH=$JAVA_HOME/jre/lib/amd64
+				SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
+				OUTPUT_DIR=../../../org.eclipse.swt.gtk64/os/freebsd/amd64
+				makefile="make_freebsd.mak"
+				echo "Building FreeBSD GTK AMD64 version of SWT"
+				;;
+			i?86)
+				AWT_LIB_PATH=$JAVA_HOME/jre/lib/i386
+				OUTPUT_DIR=../../../org.eclipse.swt.gtk/os/freebsd/x86
+				makefile="make_freebsd.mak"
+				echo "Building FreeBSD GTK x86 version of SWT"
+				;;
+			*)
+				echo "*** Unknown MODEL <${MODEL}>"
+				;;	
+		esac
+		;;
 	"SunOS")
 		CC=gcc
 		LD=gcc
@@ -138,4 +168,13 @@
 
 export CC LD JAVA_HOME QT_HOME AWT_LIB_PATH XTEST_LIB_PATH GECKO_SDK GECKO_INCLUDES GECKO_LIBS SWT_PTR_CFLAGS CDE_HOME KDE_LIB_PATH KDE_INCLUDE_PATH OUTPUT_DIR
 
-make -f $makefile ${1} ${2} ${3} ${4}
+gmake -f $makefile ${1} ${2} ${3} ${4}
+
+build_kde=`pkg_info -xc kdebase | grep "no packages match"`
+if [ "$build_kde" != "" ]; then
+  echo "Building FreeBSD version of KDE DLL."
+  gmake -f $makefile make_kde
+fi
+
+cp -p library/xpcom* .
+gmake -f $makefile make_mozilla
