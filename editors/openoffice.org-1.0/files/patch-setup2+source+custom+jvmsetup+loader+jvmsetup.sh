--- ../setup2/source/custom/jvmsetup/loader/jvmsetup.sh	Sat Mar  2 18:01:19 2002
+++ ../setup2/source/custom/jvmsetup/loader/jvmsetup.sh	Sat Mar  2 18:02:12 2002
@@ -65,6 +65,8 @@
 sd_platform=`uname -s`
 case $sd_platform in
 	SCO_SV) test=/bin/test     ;;
+	NetBSD) test=/bin/test     ;;
+	FreeBSD) test=/bin/test    ;;
 	*)      test=/usr/bin/test ;;
 esac
 
