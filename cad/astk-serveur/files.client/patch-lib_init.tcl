--- lib/init.tcl.orig	2017-07-13 07:40:52 UTC
+++ lib/init.tcl
@@ -103,7 +103,7 @@ proc init_gene { root } {
    if { $prefix == "/usr" } {
       set prefix "/"
    }
-   set ashare::prefix $prefix
+   set ashare::prefix [file join $prefix "ASTK_SERV"]
    set ashare::astkrc_ref [file join $ashare::prefix "etc" "codeaster" "astkrc"]
    catch { set ashare::astkrc_ref [file join $env(ASTER_ETC) "codeaster" "astkrc"] }
 
@@ -683,6 +683,7 @@ proc init_pltf { } {
    set astk::ihm(pltf,WIN32) "Windows"
 
    set astk::ihm(pltf,P_LINUX) "Linux x86"
+   set astk::ihm(pltf,FREEBSD) "%%unamesm%%"
    set astk::ihm(pltf,TRU64) "OSF1 TRU64"
    set astk::ihm(pltf,SOLARIS) "Solaris"
    set astk::ihm(pltf,SOLARIS64) "Solaris 64 bits"
