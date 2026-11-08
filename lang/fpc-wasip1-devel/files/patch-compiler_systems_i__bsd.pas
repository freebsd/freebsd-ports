--- compiler/systems/i_bsd.pas.orig	2026-10-18 22:31:32 UTC
+++ compiler/systems/i_bsd.pas
@@ -224,7 +224,7 @@
             res          : res_elf;
             dbg          : dbg_dwarf2;
             script       : script_unix;
-{$if defined(FreeBSD) and (defined(powerpc64le) or (defined(POWERPC64) and defined(FPC_LITTLE_ENDIAN)))}
+{$if defined(FreeBSD) and (defined(powerpc64le) or (defined(CPUPOWERPC64) and defined(FPC_LITTLE_ENDIAN)))}
             { on a FreeBSD little endian powerpc64 platform -> use little endian as default }
 	    endian       : endian_little;
 {$else}
