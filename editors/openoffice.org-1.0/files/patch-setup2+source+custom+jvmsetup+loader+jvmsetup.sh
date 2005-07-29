--- setup2/source/custom/jvmsetup/loader/jvmsetup.sh.orig	Sat Apr  6 12:22:21 2002
+++ setup2/source/custom/jvmsetup/loader/jvmsetup.sh	Wed May  1 22:38:21 2002
@@ -66,6 +66,7 @@
 case $sd_platform in
 	SCO_SV) test=/bin/test     ;;
 	NetBSD) test=/bin/test     ;;
+	FreeBSD) test=/bin/test    ;;
 	*)      test=/usr/bin/test ;;
 esac
 
