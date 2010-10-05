--- tftpd_file.c.orig	2010-10-04 18:33:31.000000000 +0800
+++ tftpd_file.c	2010-10-04 18:37:08.000000000 +0800
@@ -240,9 +240,13 @@
                break;
           case S_SEND_ACK:
                timeout_state = state;
-               tftp_send_ack(sockfd, sa, block_number);
-               if (data->trace)
-                    logger(LOG_DEBUG, "sent ACK <block: %d>", block_number);
+               result = tftp_send_ack(sockfd, sa, block_number);
+	       if (result == OK)
+	       {
+                    if (data->trace)
+                         logger(LOG_DEBUG, "sent ACK <block: %d>", 
+				block_number);
+               }
                if (all_blocks_received)
                     state = S_END;
                else
@@ -660,8 +664,12 @@
                       data->mc_port, 1);
             
                /* the socket must be unconnected for multicast */
+#ifdef __linux__
                sa->sin_family = AF_UNSPEC;
-               connect(sockfd, (struct sockaddr *)sa, sizeof(sa));
+#else
+               sa->sin_family = AF_INET;
+#endif
+               connect(sockfd, (struct sockaddr *)sa, sizeof(*sa));
 
                /* set multicast flag */
                multicast = 1;
@@ -706,10 +714,14 @@
           case S_SEND_OACK:
                timeout_state = state;
                opt_options_to_string(data->tftp_options, string, MAXLEN);
-               if (data->trace)
-                    logger(LOG_DEBUG, "sent OACK <%s>", string);
-               tftp_send_oack(sockfd, sa, data->tftp_options,
-                              data->data_buffer, data->data_buffer_size);
+               result = tftp_send_oack(sockfd, sa, data->tftp_options,
+                                       data->data_buffer,
+				       data->data_buffer_size);
+               if (result == OK)
+	       {
+		    if (data->trace)
+			 logger(LOG_DEBUG, "sent OACK <%s>", string);
+               }
                state = S_WAIT_PACKET;
                break;
           case S_SEND_DATA:
@@ -725,19 +737,25 @@
 
                if (multicast)
                {
-                    tftp_send_data(sockfd, &data->sa_mcast,
-                                   block_number + 1, data_size,
-                                   data->data_buffer);
+                    result = tftp_send_data(sockfd, &data->sa_mcast,
+                                            block_number + 1, data_size,
+                                            data->data_buffer);
                }
                else
                {
-                    tftp_send_data(sockfd, sa, block_number + 1,
-                                   data_size, data->data_buffer);
+                    result = tftp_send_data(sockfd, sa, block_number + 1,
+                                            data_size, data->data_buffer);
+               }
+
+	       if (result == ERR)
+	            state = S_ABORT;
+               else
+	       {
+                    if (data->trace)
+                         logger(LOG_DEBUG, "sent DATA <block: %d, size %d>",
+                                block_number + 1, data_size - 4);
+                    state = S_WAIT_PACKET;
                }
-               if (data->trace)
-                    logger(LOG_DEBUG, "sent DATA <block: %d, size %d>",
-                           block_number + 1, data_size - 4);
-               state = S_WAIT_PACKET;
                break;
           case S_WAIT_PACKET:
                data_size = data->data_buffer_size;
