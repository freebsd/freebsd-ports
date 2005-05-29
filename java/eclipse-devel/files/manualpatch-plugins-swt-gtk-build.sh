--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh.orig	Fri May 13 11:37:09 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh	Sat May 14 21:02:00 2005
@@ -100,6 +100,33 @@
 				;;	
 		esac
 		;;
+	"FreeBSD")
+		CC=gcc
+		LD=gcc
+		XTEST_LIB_PATH=$X11BASE/lib
+		GECKO_I=${X11BASE}/include/${BROWSER}
+		GECKO_INCLUDES="-I${GECKO_I} -I${GECKO_I}/nspr -I${GECKO_I}/xpcom -I${GECKO_I}/string -I${GECKO_I}/embed_base -I${GECKO_I}/embedstring"
+		GECKO_L=${X11BASE}/lib/${BROWSER}
+		GECKO_LIBS="-L${GECKO_L} -lxpcom -lnspr4 -lplds4 -lplc4 -lgtkembedmoz"
+		case $MODEL in
+			"amd64")
+				AWT_LIB_PATH=$JAVA_HOME/jre/lib/amd64
+				SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
+				OUTPUT_DIR=../../../org.eclipse.swt.gtk.freebsd.amd64
+				makefile="make_freebsd.mak"
+				echo "Building FreeBSD GTK AMD64 version of SWT"
+				;;
+			i?86)
+				AWT_LIB_PATH=$JAVA_HOME/jre/lib/i386
+				OUTPUT_DIR=../../../org.eclipse.swt.gtk.freebsd.x86
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
@@ -128,4 +155,4 @@
 
 export CC LD JAVA_HOME AWT_LIB_PATH XTEST_LIB_PATH GECKO_SDK GECKO_INCLUDES GECKO_LIBS SWT_PTR_CFLAGS CDE_HOME OUTPUT_DIR
 
-make -f $makefile ${1} ${2} ${3} ${4}
+gmake -f $makefile ${1} ${2} ${3} ${4}
