--- salome_adm/unix/config_files/ac_cxx_depend_flag.m4.orig	2009-03-18 20:52:30.000000000 +0600
+++ salome_adm/unix/config_files/ac_cxx_depend_flag.m4	2009-06-01 14:27:51.000000000 +0700
@@ -108,6 +108,9 @@
     uxpv*)
 	MACHINE=VPP5000
 	 ;;
+    freebsd*)
+	MACHINE=FreeBSD
+	;;
     *)
 	MACHINE=
 	 host_os_novers=$host_os
