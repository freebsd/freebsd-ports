--- source/asmc/inc/asmc.inc.orig	2026-03-12 15:51:29 UTC
+++ source/asmc/inc/asmc.inc
@@ -27,7 +27,7 @@ ifdef __UNIX__
 define _EXEC_LINK   ; Spawn linker
 
 ifdef __UNIX__
-define _ASMC_LINK <"/usr/bin/gcc">
+define _ASMC_LINK <"/usr/bin/cc">
 elseifdef MASMCOMPAT
 define _ASMC_LINK <"link.exe">
 else
