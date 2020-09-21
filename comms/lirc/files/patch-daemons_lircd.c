--- daemons/lircd.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/lircd.c
@@ -1318,7 +1318,7 @@ int send_remote(int fd, char *message, struct ir_remot
 
 	codes = remote->codes;
 	while (codes->name != NULL) {
-		len = snprintf(buffer, PACKET_SIZE, "%016llx %s\n", codes->code, codes->name);
+		len = snprintf(buffer, PACKET_SIZE, "%016llx %s\n", (unsigned long long)codes->code, codes->name);
 		if (len >= PACKET_SIZE + 1) {
 			len = sprintf(buffer, "code_too_long\n");
 		}
@@ -1338,7 +1338,7 @@ int send_name(int fd, char *message, struct ir_ncode *
 	    (write_socket_len(fd, protocol_string[P_BEGIN]) && write_socket_len(fd, message)
 	     && write_socket_len(fd, protocol_string[P_SUCCESS]) && write_socket_len(fd, protocol_string[P_DATA])))
 		return (0);
-	len = snprintf(buffer, PACKET_SIZE, "1\n%016llx %s\n", code->code, code->name);
+	len = snprintf(buffer, PACKET_SIZE, "1\n%016llx %s\n", (unsigned long long)code->code, code->name);
 	if (len >= PACKET_SIZE + 1) {
 		len = sprintf(buffer, "1\ncode_too_long\n");
 	}
