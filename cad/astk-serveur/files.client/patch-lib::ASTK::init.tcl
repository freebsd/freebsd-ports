--- lib/ASTK/init.tcl.orig	Tue Jun 10 08:58:13 2003
+++ lib/ASTK/init.tcl	Wed Jul 16 12:36:23 2003
@@ -429,6 +429,7 @@
 #################################################################
 proc init_pltf { } {
    set astk::ihm(pltf,P_LINUX) "Linux x86"
+   set astk::ihm(pltf,FREEBSD) "%%unamesm%%"
    set astk::ihm(pltf,TRU64) "OSF1 TRU64"
    set astk::ihm(pltf,SOLARIS) "Solaris"
    set astk::ihm(pltf,SOLARIS64) "Solaris 64 bits"
