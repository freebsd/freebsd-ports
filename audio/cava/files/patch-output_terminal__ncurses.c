--- output/terminal_ncurses.c.orig	2018-10-04 05:56:00 UTC
+++ output/terminal_ncurses.c
@@ -215,9 +215,13 @@ int flastd[200], int gradient) {
 // general: cleanup
 void cleanup_terminal_ncurses(void) {
 	echo();
+#ifdef __FreeBSD__
+	system("/usr/sbin/vidcontrol -f >/dev/null 2>&1");
+#else
 	system("setfont  >/dev/null 2>&1");
 	system("setfont /usr/share/consolefonts/Lat2-Fixed16.psf.gz  >/dev/null 2>&1");
 	system("setterm -blank 10");
+#endif
 	/*for(int i = 0; i < gradient_size; ++i) {
 		if(the_color_redefinitions[i].color) {
 			init_color(the_color_redefinitions[i].color,
