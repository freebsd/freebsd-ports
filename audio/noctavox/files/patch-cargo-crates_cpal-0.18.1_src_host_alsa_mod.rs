--- cargo-crates/cpal-0.18.1/src/host/alsa/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/cpal-0.18.1/src/host/alsa/mod.rs
@@ -1116,13 +1116,16 @@ fn poll_for_period(
             "Device disconnected",
         ));
     }
-    // POLLERR signals an xrun or suspend; avail_delay() below returns EPIPE/ESTRPIPE accordingly.
+    // POLLERR signals an xrun or suspend; avail_delay() below returns an error accordingly.
     // POLLIN/POLLOUT: data is ready, fall through to process it.
     let (avail_frames, delay_frames) = match stream.handle.avail_delay() {
+        // Suspend: try hardware resume first; fall back to prepare() if unsupported.
+        // BSD compat: check via PCM state rather than the Linux-specific ESTRPIPE errno.
+        Err(_) if matches!(stream.handle.state(), alsa::pcm::State::Suspended) => {
+            return try_resume(&stream.handle);
+        }
         // Xrun: recover via prepare() (+ start() for capture, handled by the worker).
         Err(err) if err.errno() == libc::EPIPE => return Err(ErrorKind::Xrun.into()),
-        // Suspend: try hardware resume first; fall back to prepare() if unsupported.
-        Err(err) if err.errno() == libc::ESTRPIPE => return try_resume(&stream.handle),
         res => res,
     }?;
     // ALSA can have spurious wakeups where poll returns but avail < avail_min.
@@ -1181,9 +1184,10 @@ fn process_input(
             }
             // EPIPE = xrun: full underrun recovery (prepare + start) required.
             Err(err) if err.errno() == libc::EPIPE => return Err(ErrorKind::Xrun.into()),
-            // ESTRPIPE = hardware suspend: try soft resume first, falling back to underrun
-            // recovery if the hardware doesn't support it.
-            Err(err) if err.errno() == libc::ESTRPIPE => {
+            // Suspend: try soft resume first, falling back to underrun recovery if the
+            // hardware doesn't support it. BSD compat: check via PCM state rather than the
+            // Linux-specific ESTRPIPE errno.
+            Err(_) if matches!(stream.handle.state(), alsa::pcm::State::Suspended) => {
                 return try_resume(&stream.handle).map(|_| ());
             }
             Err(err) => return Err(err.into()),
@@ -1249,9 +1253,10 @@ fn process_output(
             }
             // EPIPE = xrun: full underrun recovery (prepare) required.
             Err(err) if err.errno() == libc::EPIPE => return Err(ErrorKind::Xrun.into()),
-            // ESTRPIPE = hardware suspend: try soft resume first, falling back to underrun
-            // recovery if the hardware doesn't support it.
-            Err(err) if err.errno() == libc::ESTRPIPE => {
+            // Suspend: try soft resume first, falling back to underrun recovery if the
+            // hardware doesn't support it. BSD compat: check via PCM state rather than the
+            // Linux-specific ESTRPIPE errno.
+            Err(_) if matches!(stream.handle.state(), alsa::pcm::State::Suspended) => {
                 return try_resume(&stream.handle).map(|_| ());
             }
             Err(err) => return Err(err.into()),
