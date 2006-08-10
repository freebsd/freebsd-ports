--- src/game.c.orig	Sun Jun 11 04:58:34 2006
+++ src/game.c	Sun Aug  6 21:04:47 2006
@@ -7998,23 +7998,34 @@
   int action_mode = change->action_mode;
   int action_arg = change->action_arg;
   int i;
+  int level_time_value;
+  int action_arg_element;
+  int action_arg_direction;
+  int action_arg_number_min;
+  int action_arg_number_max;
+  int action_arg_number_reset;
+  int action_arg_number;
+  int action_arg_number_old;
+  int action_arg_number_new;
+  int trigger_player_bits;
+  int action_arg_player_bits;
 
   if (!change->has_action)
     return;
 
   /* ---------- determine action paramater values -------------------------- */
 
-  int level_time_value =
+  level_time_value =
     (level.time > 0 ? TimeLeft :
      TimePlayed);
 
-  int action_arg_element =
+  action_arg_element =
     (action_arg == CA_ARG_PLAYER_TRIGGER  ? change->actual_trigger_player :
      action_arg == CA_ARG_ELEMENT_TRIGGER ? change->actual_trigger_element :
      action_arg == CA_ARG_ELEMENT_TARGET  ? change->target_element :
      EL_EMPTY);
 
-  int action_arg_direction =
+  action_arg_direction =
     (action_arg >= CA_ARG_DIRECTION_LEFT &&
      action_arg <= CA_ARG_DIRECTION_DOWN ? action_arg - CA_ARG_DIRECTION :
      action_arg == CA_ARG_DIRECTION_TRIGGER ?
@@ -8023,11 +8034,11 @@
      MV_DIR_OPPOSITE(change->actual_trigger_side) :
      MV_NONE);
 
-  int action_arg_number_min =
+  action_arg_number_min =
     (action_type == CA_SET_PLAYER_SPEED ? STEPSIZE_NOT_MOVING :
      CA_ARG_MIN);
 
-  int action_arg_number_max =
+  action_arg_number_max =
     (action_type == CA_SET_PLAYER_SPEED ? STEPSIZE_EVEN_FASTER :
      action_type == CA_SET_LEVEL_GEMS ? 999 :
      action_type == CA_SET_LEVEL_TIME ? 9999 :
@@ -8036,7 +8047,7 @@
      action_type == CA_SET_CE_SCORE ? 9999 :
      CA_ARG_MAX);
 
-  int action_arg_number_reset =
+  action_arg_number_reset =
     (action_type == CA_SET_PLAYER_SPEED ? level.initial_player_stepsize[0] :
      action_type == CA_SET_LEVEL_GEMS ? level.gems_needed :
      action_type == CA_SET_LEVEL_TIME ? level.time :
@@ -8049,7 +8060,7 @@
      action_type == CA_SET_CE_SCORE ? 0 :
      0);
 
-  int action_arg_number =
+  action_arg_number =
     (action_arg <= CA_ARG_MAX ? action_arg :
      action_arg >= CA_ARG_SPEED_NOT_MOVING &&
      action_arg <= CA_ARG_SPEED_EVEN_FASTER ? (action_arg - CA_ARG_SPEED) :
@@ -8075,7 +8086,7 @@
      action_arg == CA_ARG_ELEMENT_NR_TRIGGER ? change->actual_trigger_element :
      -1);
 
-  int action_arg_number_old =
+  action_arg_number_old =
     (action_type == CA_SET_LEVEL_GEMS ? local_player->gems_still_needed :
      action_type == CA_SET_LEVEL_TIME ? TimeLeft :
      action_type == CA_SET_LEVEL_SCORE ? local_player->score :
@@ -8083,18 +8094,18 @@
      action_type == CA_SET_CE_SCORE ? ei->collect_score :
      0);
 
-  int action_arg_number_new =
+  action_arg_number_new =
     getModifiedActionNumber(action_arg_number_old,
 			    action_mode, action_arg_number,
 			    action_arg_number_min, action_arg_number_max);
 
-  int trigger_player_bits =
+  trigger_player_bits =
     (change->actual_trigger_player >= EL_PLAYER_1 &&
      change->actual_trigger_player <= EL_PLAYER_4 ?
      (1 << (change->actual_trigger_player - EL_PLAYER_1)) :
      PLAYER_BITS_ANY);
 
-  int action_arg_player_bits =
+  action_arg_player_bits =
     (action_arg >= CA_ARG_PLAYER_1 &&
      action_arg <= CA_ARG_PLAYER_4 ? action_arg - CA_ARG_PLAYER :
      action_arg == CA_ARG_PLAYER_TRIGGER ? trigger_player_bits :
