--- common/metaserver_packets.h.orig	Wed Jan  7 16:30:43 2004
+++ common/metaserver_packets.h	Wed Jan  7 16:34:45 2004
@@ -296,6 +296,7 @@
 short add_player_data_to_search_packet(char *buffer, long room_id, struct metaserver_player_aux_data 
 	*player_aux_data, void *player_data);
 
+short start_building_game_list_pref_packet(char * buffer);
 short start_building_game_list_packet(char *buffer);
 short add_game_data_to_packet(char *buffer, struct metaserver_game_aux_data *aux_data,
 	void *game_data, short game_data_length);
@@ -321,7 +322,7 @@
 short build_send_versions_packet(char *buffer);
 short build_update_info_packet(char * buffer, long size, long host, short port);
 short build_update_player_buddy_list_packet(char * buffer, struct buddy_entry * buddies);
-short build_update_order_member_list_packet(char * buffer, long member_count, struct order_member * members);
+short build_order_member_list_packet(char * buffer, long member_count, struct order_member * members);
 short build_you_just_got_blammed_sucka_packet(char * buffer, char * message);
 
 /* -------- client packets */
