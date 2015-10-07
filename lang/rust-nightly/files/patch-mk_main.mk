--- mk/main.mk.orig	2015-09-03 11:50:44 UTC
+++ mk/main.mk
@@ -107,7 +107,7 @@ ifneq ($(wildcard $(NON_BUILD_TARGET)),)
 CFG_INFO := $(info cfg: non-build target triples $(NON_BUILD_TARGET))
 endif
 
-CFG_RUSTC_FLAGS := $(RUSTFLAGS)
+CFG_RUSTC_FLAGS := $(RUSTFLAGS) -L%%LOCALBASE%%/lib
 CFG_GCCISH_CFLAGS :=
 CFG_GCCISH_LINK_FLAGS :=
 
