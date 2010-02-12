--- adm_local/unix/config_files/check_Platform.m4.orig	2009-06-08 15:38:13.000000000 +0700
+++ adm_local/unix/config_files/check_Platform.m4	2009-06-08 15:40:00.000000000 +0700
@@ -99,6 +99,9 @@
     uxpv*)
 	MACHINE=VPP5000
 	 ;;
+    freebsd*)
+	MACHINE=FreeBSD
+	;;
     *)
 	MACHINE=
 	 host_os_novers=$host_os
