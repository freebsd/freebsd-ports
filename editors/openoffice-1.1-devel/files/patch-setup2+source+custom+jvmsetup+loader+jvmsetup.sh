--- ../setup2/source/custom/jvmsetup/loader/jvmsetup.sh.orig	Fri Jun 14 15:36:11 2002
+++ ../setup2/source/custom/jvmsetup/loader/jvmsetup.sh	Fri Oct 18 23:45:45 2002
@@ -65,6 +65,7 @@
 sd_platform=`uname -s`
 case $sd_platform in
 	SCO_SV) test=/bin/test     ;;
+	FreeBSD) test=/bin/test    ;;
 	*)      test=/usr/bin/test ;;
 esac
 
