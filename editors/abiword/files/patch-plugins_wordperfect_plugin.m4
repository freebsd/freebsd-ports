--- plugins/wordperfect/plugin.m4.orig	2010-11-08 13:01:58.000000000 +0100
+++ plugins/wordperfect/plugin.m4	2016-01-26 21:13:45.479525000 +0100
@@ -1,6 +1,6 @@
 
-wordperfect_pkgs="libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0 $gsf_req"
-wordperfect_wps_pkgs='libwps-0.2 >= 0.1.0'
+wordperfect_pkgs="libwpd-0.10 $gsf_req"
+wordperfect_wps_pkgs='libwps-0.4'
 wordperfect_deps="no"
 
 WORDPERFECT_CFLAGS=
@@ -29,7 +29,7 @@
 
 PKG_CHECK_EXISTS([ $wordperfect_wps_pkgs ],
 [
-	wp_deps_pkgs="$wp_deps_pkgs $wordperfect_wps_pkgs"
+	wp_deps_pkgs="$wordperfect_wps_pkgs $wp_deps_pkgs"
 	WPS_DEFINE=" -DHAVE_LIBWPS"
 ])
 
