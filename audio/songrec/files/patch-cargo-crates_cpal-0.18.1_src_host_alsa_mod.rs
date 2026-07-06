--- cargo-crates/cpal-0.18.1/src/host/alsa/mod.rs.orig	2026-06-14 22:13:07 UTC
+++ cargo-crates/cpal-0.18.1/src/host/alsa/mod.rs
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
 
@@ -1122,7 +1130,7 @@ fn poll_for_period(
         // Xrun: recover via prepare() (+ start() for capture, handled by the worker).
         Err(err) if err.errno() == libc::EPIPE => return Err(ErrorKind::Xrun.into()),
         // Suspend: try hardware resume first; fall back to prepare() if unsupported.
-        Err(err) if err.errno() == libc::ESTRPIPE => return try_resume(&stream.handle),
+        Err(err) if err.errno() == ESTRPIPE => return try_resume(&stream.handle),
         res => res,
     }?;
     // ALSA can have spurious wakeups where poll returns but avail < avail_min.
@@ -1183,7 +1191,7 @@ fn process_input(
             Err(err) if err.errno() == libc::EPIPE => return Err(ErrorKind::Xrun.into()),
             // ESTRPIPE = hardware suspend: try soft resume first, falling back to underrun
             // recovery if the hardware doesn't support it.
-            Err(err) if err.errno() == libc::ESTRPIPE => {
+            Err(err) if err.errno() == ESTRPIPE => {
                 return try_resume(&stream.handle).map(|_| ());
             }
             Err(err) => return Err(err.into()),
@@ -1251,7 +1259,7 @@ fn process_output(
             Err(err) if err.errno() == libc::EPIPE => return Err(ErrorKind::Xrun.into()),
             // ESTRPIPE = hardware suspend: try soft resume first, falling back to underrun
             // recovery if the hardware doesn't support it.
-            Err(err) if err.errno() == libc::ESTRPIPE => {
+            Err(err) if err.errno() == ESTRPIPE => {
                 return try_resume(&stream.handle).map(|_| ());
             }
             Err(err) => return Err(err.into()),
