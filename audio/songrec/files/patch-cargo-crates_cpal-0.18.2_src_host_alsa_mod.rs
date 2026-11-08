--- cargo-crates/cpal-0.18.2/src/host/alsa/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/cpal-0.18.2/src/host/alsa/mod.rs
@@ -92,6 +92,14 @@ const DEFAULT_PERIODS: alsa::pcm::Frames = 2;
 const DEFAULT_DEVICE: &str = "default";
 const DEFAULT_PERIODS: alsa::pcm::Frames = 2;
 
+// ESTRPIPE is Linux-specific (hardware suspend from ALSA); not present on FreeBSD.
+// The ALSA compatibility library on FreeBSD never returns this, so defining it as an
+// out-of-range sentinel ensures the match arms are unreachable without compile errors.
+#[cfg(target_os = "linux")]
+const ESTRPIPE: libc::c_int = libc::ESTRPIPE;
+#[cfg(not(target_os = "linux"))]
+const ESTRPIPE: libc::c_int = 86;
+
 // Some ALSA plugins (e.g. alsaequal, certain USB drivers) are not reentrant.
 static ALSA_OPEN_MUTEX: std::sync::Mutex<()> = std::sync::Mutex::new(());
 
