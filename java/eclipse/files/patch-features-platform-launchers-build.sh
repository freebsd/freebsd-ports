--- features/org.eclipse.platform.launchers/library/gtk/build.sh.orig	Thu Jul 27 18:07:06 2006
+++ features/org.eclipse.platform.launchers/library/gtk/build.sh	Wed Jul 26 18:19:38 2006
@@ -92,6 +92,23 @@
 				;;
 		esac
 		;;
+	"FreeBSD")
+		makefile="make_freebsd.mak"
+                defaultOS="freebsd"
+                case $MODEL in
+                        "amd64")
+                                defaultOSArch="amd64"
+                                OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
+                                ;;
+                        i?86)
+                                defaultOSArch="x86"
+                                OUTPUT_DIR="../../bin/$defaultWS/$defaultOS/$defaultOSArch"
+                                ;;
+                        *)
+                                echo "*** Unknown MODEL <${MODEL}>"
+                                ;;
+                esac
+                ;;		
 	*)
 	echo "Unknown OS -- build aborted"
 	;;
