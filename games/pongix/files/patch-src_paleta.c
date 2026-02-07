--- src/paleta.c.orig	2005-12-27 05:37:27.000000000 +0000
+++ src/paleta.c
@@ -89,7 +89,7 @@ void paleta_manejar_con_teclado (Paleta 
 {
 }
 
-int paleta_recibir_pos (Paleta * data, TCPsocket origen)
+void paleta_recibir_pos (Paleta * data, TCPsocket origen)
 {
 	char buffer [5];
 	
@@ -104,7 +104,7 @@ int paleta_recibir_pos (Paleta * data, T
 	data->y = atoi (buffer);
 }
 
-int paleta_enviar_pos (Paleta * data, TCPsocket destino)
+void paleta_enviar_pos (Paleta * data, TCPsocket destino)
 {
 	char buffer [5];
 	
