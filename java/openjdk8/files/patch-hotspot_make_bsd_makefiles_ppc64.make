--- hotspot/make/bsd/makefiles/ppc64.make.orig	2024-01-02 13:01:01 UTC
+++ hotspot/make/bsd/makefiles/ppc64.make
@@ -37,11 +37,7 @@ ifeq ($(OPENJDK_TARGET_CPU_ENDIAN),big)
 endif
 
 ifeq ($(OPENJDK_TARGET_CPU_ENDIAN),big)
-  # fixes `relocation truncated to fit' error for gcc 4.1.
-  CFLAGS += -mminimal-toc
-
-  # finds use ppc64 instructions, but schedule for power5
-  CFLAGS += -mcpu=powerpc64 -mtune=power5 -minsert-sched-nops=regroup_exact -mno-multiple -mno-string
+  CFLAGS += -mcpu=powerpc64 -mtune=power5 -DABI_ELFv2
 else
   # Little endian machine uses ELFv2 ABI.
   CFLAGS += -DVM_LITTLE_ENDIAN -DABI_ELFv2
