--- mk/rt.mk.orig	2016-07-17 07:06:29 UTC
+++ mk/rt.mk
@@ -270,8 +270,7 @@ COMPRT_DEFINES_$(1) := -DCOMPILER_RT_ENA
 endif
 
 ifndef COMPRT_DIR_$(1)
-# NB: FreeBSD and NetBSD output to "linux"...
-COMPRT_DIR_$(1) := linux
+COMPRT_DIR_$(1) := $$(word 3, $$(subst -, , $(1)))
 COMPRT_ARCH_$(1) := $$(patsubst i586,i386,$$(COMPRT_ARCH_$(1)))
 
 ifeq ($$(findstring android,$(1)),android)
