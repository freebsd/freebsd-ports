Return struct like OpenBSD, see src/librustc_trans/cabi_x86.rs

--- src/librustc_back/target/freebsd_base.rs.orig	2017-07-17 22:10:50 UTC
+++ src/librustc_back/target/freebsd_base.rs
@@ -31,6 +31,7 @@ pub fn opts() -> TargetOptions {
         target_family: Some("unix".to_string()),
         linker_is_gnu: true,
         has_rpath: true,
+        is_like_openbsd: true,
         pre_link_args: args,
         position_independent_executables: true,
         exe_allocation_crate: super::maybe_jemalloc(),
