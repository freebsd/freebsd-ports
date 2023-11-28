--- compiler/rustc_target/src/spec/targets/i686_unknown_freebsd.rs.orig	2023-11-27 08:52:00 UTC
+++ compiler/rustc_target/src/spec/targets/i686_unknown_freebsd.rs
@@ -2,7 +2,7 @@ pub fn target() -> Target {
 
 pub fn target() -> Target {
     let mut base = base::freebsd::opts();
-    base.cpu = "pentium4".into();
+    base.cpu = "pentiumpro".into();
     base.max_atomic_width = Some(64);
     base.add_pre_link_args(LinkerFlavor::Gnu(Cc::Yes, Lld::No), &["-m32", "-Wl,-znotext"]);
     base.stack_probes = StackProbeType::X86;
