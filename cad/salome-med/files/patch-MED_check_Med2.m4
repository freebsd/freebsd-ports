--- adm_local/unix/config_files/check_Med2.m4.orig	2009-06-03 16:35:02.000000000 +0700
+++ adm_local/unix/config_files/check_Med2.m4	2009-06-03 16:35:32.000000000 +0700
@@ -141,6 +141,9 @@
     uxpv*)
 	MACHINE=VPP5000
 	 ;;
+    freebsd*)
+	MACHINE=FreeBSD
+	;;
     *)
 	MACHINE=
 	 host_os_novers=$host_os
