--- mysys/crc32/crc32c.cc.orig	2024-06-14 12:14:03 UTC
+++ mysys/crc32/crc32c.cc
@@ -455,7 +455,7 @@ static int arch_ppc_probe(void) {
 
   return arch_ppc_crc32;
 }
-# elif defined __FreeBSD_version && __FreeBSD_version >= 1200000
+# elif defined __FreeBSD__
 #  include <machine/cpu.h>
 #  include <sys/auxv.h>
 #  include <sys/elf_common.h>
