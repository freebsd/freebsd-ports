--- hotspot/make/bsd/makefiles/ppc64.make.orig	2020-11-18 23:45:09 UTC
+++ hotspot/make/bsd/makefiles/ppc64.make
@@ -47,5 +47,5 @@ else
   CFLAGS += -DVM_LITTLE_ENDIAN -DABI_ELFv2
 
   # Use Power8, this is the first CPU to support PPC64 LE with ELFv2 ABI.
-  CFLAGS += -mcpu=power7 -mtune=power8 -minsert-sched-nops=regroup_exact -mno-multiple -mno-string
+  CFLAGS += -mcpu=power8 -mtune=power8
 endif
