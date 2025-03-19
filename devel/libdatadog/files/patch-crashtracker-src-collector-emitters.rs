--- crashtracker/src/collector/emitters.rs.orig	2025-02-11 17:46:31 UTC
+++ crashtracker/src/collector/emitters.rs
@@ -151,7 +151,7 @@ fn emit_proc_self_maps(w: &mut impl Write) -> anyhow::
     Ok(())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 fn emit_ucontext(w: &mut impl Write, ucontext: *const ucontext_t) -> anyhow::Result<()> {
     anyhow::ensure!(!ucontext.is_null());
     writeln!(w, "{DD_CRASHTRACK_BEGIN_UCONTEXT}")?;
