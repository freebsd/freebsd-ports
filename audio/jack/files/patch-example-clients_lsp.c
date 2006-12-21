--- example-clients/lsp.c.orig	Fri May 26 11:45:08 2006
+++ example-clients/lsp.c	Thu Dec  7 16:58:45 2006
@@ -120,9 +120,9 @@
 	ports = jack_get_ports (client, NULL, NULL, 0);
 
 	for (i = 0; ports[i]; ++i) {
-		printf ("%s\n", ports[i]);
-
 		jack_port_t *port = jack_port_by_name (client, ports[i]);
+
+		printf ("%s\n", ports[i]);
 
 		if (show_con) {
 			if ((connections = jack_port_get_all_connections (client, jack_port_by_name(client, ports[i]))) != 0) {
