--- lib/init.tcl.orig	2011-12-20 13:33:00.000000000 +0100
+++ lib/init.tcl	2012-05-08 12:55:11.000000000 +0200
@@ -100,7 +100,7 @@
    if { $prefix == "/usr" } {
       set prefix "/"
    }
-   set ashare::prefix $prefix
+   set ashare::prefix [file join $prefix "ASTK_SERV"]
    set ashare::astkrc_ref [file join $ashare::prefix "etc" "codeaster" "astkrc"]
 
    #  numero de version de astk
@@ -673,6 +673,7 @@
    set astk::ihm(pltf,WIN32) "Windows"
 
    set astk::ihm(pltf,P_LINUX) "Linux x86"
+   set astk::ihm(pltf,FREEBSD) "%%unamesm%%"
    set astk::ihm(pltf,TRU64) "OSF1 TRU64"
    set astk::ihm(pltf,SOLARIS) "Solaris"
    set astk::ihm(pltf,SOLARIS64) "Solaris 64 bits"
