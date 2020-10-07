--- src/unix.rs.orig	2020-10-06 00:22:27 UTC
+++ src/unix.rs
@@ -45,7 +45,7 @@ fn xdg_dirs(xdg_type: &str, def_home_suffix: &str, def
 }
 
 /// Return configuration directories for UNIX systems
-pub fn conf_dirs() -> Vec<String> { xdg_dirs("CONFIG", "/.config", "/etc/xdg:/etc") }
+pub fn conf_dirs() -> Vec<String> { xdg_dirs("CONFIG", "/.config", "/etc/xdg:%%PREFIX%%/etc") }
 
 /// Return syntax directories for UNIX systems
 pub fn data_dirs() -> Vec<String> {
@@ -59,7 +59,7 @@ pub fn data_dirs() -> Vec<String> {
 /// This ioctl is described here: <http://man7.org/linux/man-pages/man4/tty_ioctl.4.html>
 pub fn get_window_size() -> Result<(usize, usize), Error> {
     let mut maybe_ws = std::mem::MaybeUninit::<winsize>::uninit();
-    cerr(unsafe { libc::ioctl(STDOUT_FILENO, TIOCGWINSZ, maybe_ws.as_mut_ptr()) })
+    cerr(unsafe { libc::ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), maybe_ws.as_mut_ptr()) })
         .map_or(None, |_| unsafe { Some(maybe_ws.assume_init()) })
         .filter(|ws| ws.ws_col != 0 && ws.ws_row != 0)
         .map_or(Err(Error::InvalidWindowSize), |ws| Ok((ws.ws_row as usize, ws.ws_col as usize)))
