--- src/interfaces/tty.c.orig	2024-07-27 05:20:14 UTC
+++ src/interfaces/tty.c
@@ -248,7 +248,6 @@ static void if_tty_start(void)
     //use_tioctl(true);
     initscr();
     start_color();
-    raw();
     cbreak(); // <-- re-enables signal processing after raw() disables
     intrflush(stdscr, false);
     noecho();
