--- cargo-crates/pbr-1.0.0/src/tty/unix.rs.orig	2018-05-16 20:03:56 UTC
+++ cargo-crates/pbr-1.0.0/src/tty/unix.rs
@@ -19,7 +19,7 @@ pub fn terminal_size() -> Option<(Width, Height)> {
             ws_xpixel: 0,
             ws_ypixel: 0,
         };
-        ioctl(STDOUT_FILENO, TIOCGWINSZ, &mut winsize);
+        ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &mut winsize);
         let rows = if winsize.ws_row > 0 {
             winsize.ws_row
         } else {
