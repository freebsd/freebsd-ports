$FreeBSD$

--- src/m_conf.c.orig	Fri Mar 21 04:46:29 2003
+++ src/m_conf.c	Tue Nov 11 22:42:47 2003
@@ -32,7 +32,7 @@ void x_interface_setup(void);
 void x_connective_setup(void);
 void x_time_setup(void);
 void x_arithmetic_setup(void);
-void x_midi_setup(void);
+//void x_midi_setup(void);
 void x_misc_setup(void);
 void x_net_setup(void);
 void x_qlist_setup(void);
@@ -78,7 +78,7 @@ void conf_init(void)
     x_connective_setup();
     x_time_setup();
     x_arithmetic_setup();
-    x_midi_setup();
+//    x_midi_setup();
     x_misc_setup();
     x_net_setup();
     x_qlist_setup();
