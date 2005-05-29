--- plugins/org.eclipse.swt/Eclipse SWT PI/motif/library/build.sh.orig	Fri May 13 11:37:09 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/motif/library/build.sh	Sat May 14 21:03:05 2005
@@ -54,6 +54,18 @@
 			echo "Building Linux motif x86 version of SWT"
 		esac
 		;;
+	"FreeBSD")
+		case $MODEL in
+		i?86) 
+			OUTPUT_DIR=../../../org.eclipse.swt.motif.freebsd.x86
+			makefile="make_freebsd.mak"
+			echo "Building FreeBSD motif x86 version of SWT"
+			;;
+		*)
+			echo "*** Unknown MODEL <${MODEL}>"
+			;;	
+		esac
+		;;
 	"SunOS")
 		case $MODEL in
 		*) 
@@ -113,4 +125,4 @@
 
 export JAVA_HOME MOTIF_HOME CDE_HOME OUTPUT_DIR
 
-make -f $makefile $1 $2 $3 $4
\ No newline at end of file
+gmake -f $makefile $1 $2 $3 $4
