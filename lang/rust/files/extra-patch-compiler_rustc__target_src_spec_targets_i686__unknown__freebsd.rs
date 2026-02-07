i386 should be pentiumpro (no SSE2, no ...)

--- compiler/rustc_target/src/spec/targets/i686_unknown_freebsd.rs.orig	2023-12-22 11:18:00 UTC
+++ compiler/rustc_target/src/spec/targets/i686_unknown_freebsd.rs
@@ -3,7 +3,7 @@ pub(crate) fn target() -> Target {
 pub(crate) fn target() -> Target {
     let mut base = base::freebsd::opts();
     base.rustc_abi = Some(RustcAbi::X86Sse2);
-    base.cpu = "pentium4".into();
+    base.cpu = "pentiumpro".into();
     base.max_atomic_width = Some(64);
     base.add_pre_link_args(LinkerFlavor::Gnu(Cc::Yes, Lld::No), &["-m32", "-Wl,-znotext"]);
     base.stack_probes = StackProbeType::Inline;
