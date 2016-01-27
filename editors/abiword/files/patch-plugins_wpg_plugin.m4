--- plugins/wpg/plugin.m4.orig	2010-11-08 13:01:58.000000000 +0100
+++ plugins/wpg/plugin.m4	2016-01-26 20:42:41.493892000 +0100
@@ -1,5 +1,5 @@
 
-wpg_pkgs="$gsf_req libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0"
+wpg_pkgs="libwpg-0.3 $gsf_req"
 wpg_deps="no"
 
 if test "$enable_wpg" != ""; then
