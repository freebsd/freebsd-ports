--- output/terminal_ncurses.c.orig	2020-05-29 23:00:32 UTC
+++ output/terminal_ncurses.c
@@ -262,9 +262,13 @@ int draw_terminal_ncurses(int is_tty, int terminal_hei
 // general: cleanup
 void cleanup_terminal_ncurses(void) {
     echo();
+#ifdef __FreeBSD__
+    system("/usr/sbin/vidcontrol -f >/dev/null 2>&1");
+#else
     system("setfont  >/dev/null 2>&1");
     system("setfont /usr/share/consolefonts/Lat2-Fixed16.psf.gz  >/dev/null 2>&1");
     system("setterm -blank 10  >/dev/null 2>&1");
+#endif
     /*for(int i = 0; i < gradient_size; ++i) {
             if(the_color_redefinitions[i].color) {
                     init_color(the_color_redefinitions[i].color,
