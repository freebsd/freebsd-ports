--- trackercore/player_data_effects.cpp.orig	Tue Apr 30 14:58:11 2002
+++ trackercore/player_data_effects.cpp	Fri Dec 27 22:36:36 2002
@@ -339,7 +339,7 @@
 
 		if (song->variables.use_linear_slides) {
 
-			control.channel[p_track].period=control.channel[p_track].aux_period-abs(get_period((Uint16)46,0)-get_period((Uint16)44,0))*note;
+			control.channel[p_track].period=control.channel[p_track].aux_period-abs((int)(get_period((Uint16)46,0)-get_period((Uint16)44,0)))*note;
 		} else {
 
 			control.channel[p_track].period=get_period( (((Uint16)control.channel[p_track].note+control.channel[p_track].sample_ptr->data.note_offset)+note)<<1,control.channel[p_track].sample_ptr->data.finetune);
