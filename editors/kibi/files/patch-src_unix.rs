--- src/unix.rs.orig	2025-11-04 01:20:03 UTC
+++ src/unix.rs
@@ -29,7 +29,7 @@ pub fn get_window_size() -> Result<(usize, usize), Err
 /// This ioctl is described here: <http://man7.org/linux/man-pages/man4/tty_ioctl.4.html>
 pub fn get_window_size() -> Result<(usize, usize), Error> {
     let mut maybe_ws = std::mem::MaybeUninit::<winsize>::uninit();
-    cerr(unsafe { libc::ioctl(STDOUT_FILENO, TIOCGWINSZ, maybe_ws.as_mut_ptr()) })
+    cerr(unsafe { libc::ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), maybe_ws.as_mut_ptr()) })
         .map_or(None, |()| unsafe { Some(maybe_ws.assume_init()) })
         .filter(|ws| ws.ws_col != 0 && ws.ws_row != 0)
         .map_or(Err(Error::InvalidWindowSize), |ws| Ok((ws.ws_row as usize, ws.ws_col as usize)))
