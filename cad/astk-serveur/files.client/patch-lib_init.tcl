--- ./lib/init.tcl.orig	2009-12-23 15:53:05.000000000 +0100
+++ ./lib/init.tcl	2010-01-26 23:25:44.000000000 +0100
@@ -603,6 +603,7 @@
    set astk::ihm(pltf,WIN32) "Windows"
    
    set astk::ihm(pltf,P_LINUX) "Linux x86"
+   set astk::ihm(pltf,FREEBSD) "%%unamesm%%"
    set astk::ihm(pltf,TRU64) "OSF1 TRU64"
    set astk::ihm(pltf,SOLARIS) "Solaris"
    set astk::ihm(pltf,SOLARIS64) "Solaris 64 bits"
