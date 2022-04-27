--- config/makefiles/rust.mk.orig	2022-04-02 10:37:19 UTC
+++ config/makefiles/rust.mk
@@ -221,7 +221,6 @@
 ifneq (,$(PKG_CONFIG_LIBDIR))
 export PKG_CONFIG_LIBDIR
 endif
-export RUST_BACKTRACE=full
 export MOZ_TOPOBJDIR=$(topobjdir)
 export MOZ_FOLD_LIBS
 export PYTHON3
