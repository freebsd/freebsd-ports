--- ld/emulparams/elf32lriscv-defs.sh.orig	2020-02-03 18:09:14 UTC
+++ ld/emulparams/elf32lriscv-defs.sh
@@ -16,15 +16,8 @@ if test `echo "$host" | sed -e s/64//` = `echo "$targe
   esac
 fi
 
-# Enable shared library support for everything except an embedded elf target.
-case "$target" in
-  riscv*-elf)
-    ;;
-  *)
-    GENERATE_SHLIB_SCRIPT=yes
-    GENERATE_PIE_SCRIPT=yes
-    ;;
-esac
+GENERATE_SHLIB_SCRIPT=yes
+GENERATE_PIE_SCRIPT=yes
 
 TEXT_START_ADDR=0x10000
 MAXPAGESIZE="CONSTANT (MAXPAGESIZE)"
