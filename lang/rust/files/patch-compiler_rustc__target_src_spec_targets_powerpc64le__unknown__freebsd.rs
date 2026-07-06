--- compiler/rustc_target/src/spec/targets/powerpc64le_unknown_freebsd.rs.orig	2026-06-04 11:55:17.704125811 +0200
+++ compiler/rustc_target/src/spec/targets/powerpc64le_unknown_freebsd.rs	2026-06-04 12:02:00.992258644 +0200
@@ -6,6 +6,10 @@
     let mut base = base::freebsd::opts();
     base.cpu = "ppc64le".into();
     base.add_pre_link_args(LinkerFlavor::Gnu(Cc::Yes, Lld::No), &["-m64"]);
+    // long double is IEEE-128; f128 soft-float ops emit the PPC __*kf* helpers,
+    // which compiler_builtins lacks. Resolve them from base libgcc.
+    base.late_link_args.entry(LinkerFlavor::Gnu(Cc::Yes, Lld::No)).or_default().push("-lgcc".into());
+    base.late_link_args.entry(LinkerFlavor::Gnu(Cc::Yes, Lld::Yes)).or_default().push("-lgcc".into());
     base.max_atomic_width = Some(64);
     base.stack_probes = StackProbeType::Inline;
     base.abi = Abi::ElfV2;
