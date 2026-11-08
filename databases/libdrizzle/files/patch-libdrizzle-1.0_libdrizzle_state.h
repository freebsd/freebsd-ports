--- libdrizzle-1.0/libdrizzle/state.h.orig	2026-11-06 18:08:06 UTC
+++ libdrizzle-1.0/libdrizzle/state.h
@@ -81,6 +81,7 @@ drizzle_return_t drizzle_state_handshake_result_read(d
 drizzle_return_t drizzle_state_handshake_client_read(drizzle_con_st *con);
 drizzle_return_t drizzle_state_handshake_client_write(drizzle_con_st *con);
 drizzle_return_t drizzle_state_handshake_result_read(drizzle_con_st *con);
+drizzle_return_t drizzle_state_auth_write(drizzle_con_st *con);
 
 /* Functions in command.c */
 drizzle_return_t drizzle_state_command_read(drizzle_con_st *con);
