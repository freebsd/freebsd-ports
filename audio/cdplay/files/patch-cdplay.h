--- cdplay.h.orig	1997-11-17 07:21:55 UTC
+++ cdplay.h
@@ -71,8 +71,9 @@ void next(void);
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
@@ -90,6 +91,7 @@ void hs_cont(void);
 void hs_winch(void);
 void do_exit(int);
 void do_stop(void);
+void getcommand(char *command, int *repetivity);
 
 /* Awesome!!1!!1! 2 sound functions */
 void more_vol(void);
