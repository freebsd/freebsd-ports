--- screendef.h.orig	2020-08-28 12:43:47 UTC
+++ screendef.h
@@ -334,9 +334,9 @@ extern int fft3_totmem;
 extern int radar_totmem;
 extern int s_meter_avg_filled_flag;
 
-int w3sz_offset_hz;  //w3sz offset equal to ug.par2 to be used elsewhere in program
-int w3sz_offset_hz_old;  //w3sz 
-int w3sz_users_flag;//w3sz
+extern int w3sz_offset_hz;  //w3sz offset equal to ug.par2 to be used elsewhere in program
+extern int w3sz_offset_hz_old;  //w3sz 
+extern int w3sz_users_flag;//w3sz
 
 extern ROUTINE current_mouse_activity;
 extern int mouse_active_flag;
