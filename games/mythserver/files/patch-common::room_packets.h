--- common/room_packets.h.orig	Wed Jan  7 16:56:11 2004
+++ common/room_packets.h	Wed Jan  7 16:54:55 2004
@@ -417,6 +417,11 @@
 	unsigned long player_id,
 	char * player_information);
 
+short build_rs_player_enter_room_packet(
+	char * buffer, 
+	long player_id, 
+	long room_id);
+
 short build_rs_player_info_request_packet(
 	char * buffer,
 	unsigned long player_id,
@@ -430,6 +435,11 @@
 short build_rs_score_game_packet(
 	char * buffer, 
 	struct game_data * game);
+
+short build_rs_player_leave_room_packet(
+	char * buffer, 
+	long player_id, 
+	long room_id);
 
 boolean byteswap_room_packet(
 	char * buffer, 
