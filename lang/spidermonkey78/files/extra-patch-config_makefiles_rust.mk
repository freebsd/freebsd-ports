--- config/makefiles/rust.mk.orig	2022-04-02 10:37:19 UTC
+++ config/makefiles/rust.mk
@@ -171,7 +171,6 @@ export LIBCLANG_PATH=$(MOZ_LIBCLANG_PATH)
 export CLANG_PATH=$(MOZ_CLANG_PATH)
 export PKG_CONFIG
 export PKG_CONFIG_ALLOW_CROSS=1
-export RUST_BACKTRACE=full
 export MOZ_TOPOBJDIR=$(topobjdir)
 
 # Set COREAUDIO_SDK_PATH for third_party/rust/coreaudio-sys/build.rs
