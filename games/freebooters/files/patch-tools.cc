
$FreeBSD$

--- tools.cc.orig	Thu Sep 30 00:32:43 2004
+++ tools.cc	Thu Sep 30 00:45:46 2004
@@ -46,7 +46,7 @@
    path_to_data_dir = "";
    return;
 #else
-   readdata config("/etc/freebooters.conf");
+   readdata config("%%PREFIX%%/etc/freebooters.conf");
 
    if (config.get_str("datadir") == "")
       path_to_data_dir = "";
