
$FreeBSD$

--- ./cdplay.h.orig	Mon May 19 15:44:41 2003
+++ ./cdplay.h	Mon May 19 15:55:12 2003
@@ -71,8 +71,9 @@
 void prev(void);
 void stop(void);
 void cdpause(void);
-void ff(void);
-void rew(void);
+void cdsoftpause(void);
+void ff(int);
+void rew(int);
 void eject(void);
 
 /* Terminal related functions */
@@ -90,6 +91,7 @@
 void hs_winch(void);
 void do_exit(int);
 void do_stop(void);
+void getcommand(char *command, int *repetivity);
 
 /* Awesome!!1!!1! 2 sound functions */
 void more_vol(void);
