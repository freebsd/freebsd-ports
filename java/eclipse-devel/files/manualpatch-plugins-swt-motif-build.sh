--- plugins/org.eclipse.swt/Eclipse SWT PI/motif/library/build.sh	Fri Apr  1 13:55:27 2005
+++ ../files/plugins-swt-motif-build.sh	Sun Apr  3 16:38:13 2005
@@ -57,6 +57,18 @@
 			echo "Building Linux motif x86 version of SWT"
 		esac
 		;;
+	"FreeBSD")
+		case $MODEL in
+		i?86) 
+			OUTPUT_DIR=../../../org.eclipse.swt.motif/os/freebsd/x86
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
