--- src/client.c
+++ src/client.c
@@ -90,8 +90,6 @@
 
 extern server_info_t info;
 
-static void client_send_fake_file (connection_t *con);
-
 /* Brand new client. Check what he wants, and either add him to
    the correct tree of clients (inside a source), or kill him off */
 void client_login(connection_t *con, char *expr)
