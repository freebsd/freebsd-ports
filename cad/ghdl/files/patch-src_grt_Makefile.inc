- workaround for https://github.com/ghdl/ghdl/issues/2358

--- src/grt/Makefile.inc.orig	2023-02-23 18:08:23 UTC
+++ src/grt/Makefile.inc
@@ -43,7 +43,7 @@ else
 endif
 
 # Standard GRT_EXEC_OPTS value for ELF platforms.
-GRT_ELF_EXEC_OPTS:=-Wl,--version-script=@/grt.ver -Wl,--export-dynamic
+GRT_ELF_EXEC_OPTS:=#-Wl,--version-script=@/grt.ver -Wl,--export-dynamic
 
 # These conditions define these variables:
 #  GRT_TARGET_OBJS: platform specific files to be added in the grt library
