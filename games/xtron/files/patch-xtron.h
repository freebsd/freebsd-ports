--- xtron.h.orig	1995-04-16 12:48:20 UTC
+++ xtron.h
@@ -40,11 +40,11 @@ struct Player {
   int alive;
   enum directions plr_dir;
   enum play_types plr_type; 
-} p[2];
+};
 
 struct Board {
   short int contents[200][200];
-} b;
+};
  
 void plr_setup(void);
 int plr_checkmove(int p_num, int new_val, int axis_type, enum directions dir);
