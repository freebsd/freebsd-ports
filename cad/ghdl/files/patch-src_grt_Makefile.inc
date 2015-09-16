--- src/grt/Makefile.inc.orig	2015-06-01 05:56:40 UTC
+++ src/grt/Makefile.inc
@@ -71,6 +71,11 @@ ifeq ($(filter-out x86_64 freebsd%,$(arc
   GRT_EXTRA_LIB=-lm $(GRT_ELF_OPTS)
   ADAC=ada
 endif
+ifeq ($(filter-out x86_64 dragonfly%,$(arch) $(osys)),)
+  GRT_TARGET_OBJS=amd64.o linux.o times.o
+  GRT_EXTRA_LIB=-lm $(GRT_ELF_OPTS)
+  ADAC=ada
+endif
 ifeq ($(filter-out i%86 darwin%,$(arch) $(osys)),)
   GRT_TARGET_OBJS=i386.o linux.o times.o
   GRT_EXTRA_LIB=
