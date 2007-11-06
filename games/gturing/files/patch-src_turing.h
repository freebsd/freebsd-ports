--- src/turing.h.orig	2007-11-06 11:32:13.000000000 +0100
+++ src/turing.h	2007-11-06 11:32:35.000000000 +0100
@@ -56,9 +56,6 @@
 }
 turing;
 
-extern gchar states_fname[1024];
-extern gchar tape_string[1024];
-
 extern turing *turing_new(void);
 extern gchar *turing_states_to_string(turing_state *state);
 extern gint turing_fread_states(turing *machine, gchar *filename);
