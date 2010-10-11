--- tftpd_file.c.orig	2004-02-18 10:21:47.000000000 +0800
+++ tftpd_file.c	2010-10-11 13:22:54.000000000 +0800
@@ -89,6 +89,28 @@
      return OK;
 }
 
+int opt_same_file(struct tftp_opt *opt1, struct tftp_opt *opt2)
+{
+     if ((strncmp(opt1->option, "filename", OPT_SIZE) == 0) &&
+         (strncmp(opt2->option, "filename", OPT_SIZE) == 0))
+     {
+          char tofilename[MAXLEN];
+          char fromfilename[MAXLEN];
+          struct stat tostat;
+          struct stat fromstat;
+
+          Strncpy(tofilename, opt1->value, MAXLEN);
+          tftpd_rules_check(tofilename);
+          Strncpy(fromfilename, opt2->value, MAXLEN);
+          tftpd_rules_check(fromfilename);
+          if (stat(tofilename, &tostat) || stat(fromfilename, &fromstat))
+               return 0;
+
+          return (tostat.st_ino == fromstat.st_ino);
+     }
+     return 0;
+}
+
 /*
  * Receive a file. It is implemented as a state machine using a while loop
  * and a switch statement. Function flow is as follow:
@@ -117,7 +139,6 @@
      char filename[MAXLEN];
      char string[MAXLEN];
      int timeout = data->timeout;
-     int number_of_timeout = 0;
      int all_blocks_received = 0; /* temporary kludge */
      int convert = 0;           /* if true, do netascii convertion */
 
@@ -240,9 +261,13 @@
                break;
           case S_SEND_ACK:
                timeout_state = state;
-               tftp_send_ack(sockfd, sa, block_number);
-               if (data->trace)
-                    logger(LOG_DEBUG, "sent ACK <block: %d>", block_number);
+               result = tftp_send_ack(sockfd, sa, block_number);
+               if (result == OK)
+               {
+                    if (data->trace)
+                         logger(LOG_DEBUG, "sent ACK <block: %d>", 
+                                block_number);
+               }
                if (all_blocks_received)
                     state = S_END;
                else
@@ -265,8 +290,8 @@
                switch (result)
                {
                case GET_TIMEOUT:
-                    number_of_timeout++;
-                    if (number_of_timeout > NB_OF_RETRY)
+                    data->client_info->number_of_timeout++;
+                    if (data->client_info->number_of_timeout > NB_OF_RETRY)
                     {
                          logger(LOG_INFO, "client (%s) not responding",
                                 inet_ntoa(data->client_info->client.sin_addr));
@@ -322,7 +347,7 @@
                          else
                               logger(LOG_WARNING, "source port mismatch, check bypassed");
                     }
-                    number_of_timeout = 0;
+                    data->client_info->number_of_timeout = 0;
                     state = S_DATA_RECEIVED;
                     break;
                case GET_DISCARD:
@@ -413,13 +438,13 @@
      char filename[MAXLEN];
      char string[MAXLEN];
      int timeout = data->timeout;
-     int number_of_timeout = 0;
      int mcast_switch = data->mcast_switch_client;
      struct stat file_stat;
      int convert = 0;           /* if true, do netascii conversion */
      struct thread_data *thread = NULL; /* used when looking for a multicast
                                            thread */
      int multicast = 0;         /* set to 1 if multicast */
+     time_t last_send_time = -1;
 
      struct client_info *client_info = data->client_info;
      struct client_info *client_old = NULL;
@@ -428,6 +453,8 @@
      int prev_block_number = 0; /* needed to support netascii convertion */
      int prev_file_pos = 0;
      int temp = 0;
+     int total_bytes_sent = 0;
+     int clients_served = 0;
 
      /* look for mode option */
      if (strcasecmp(data->tftp_options[OPT_MODE].value, "netascii") == 0)
@@ -535,6 +562,34 @@
                return ERR;
           }
 
+          /* make sure that the oack packet will fit in the buffer */
+	  int oacklen = 2;
+	  int i;
+	  for (i = 2; i < OPT_NUMBER; i++)
+	  {
+	       if (data->tftp_options[i].enabled && 
+		   data->tftp_options[i].specified)
+               {
+		    oacklen += strlen(data->tftp_options[i].option);
+		    oacklen++;
+		    oacklen += strlen(data->tftp_options[i].value);
+		    oacklen++;
+               }
+          }
+
+	  if (oacklen > result)
+	  {
+               logger(LOG_NOTICE, "OACK will not fit in buffer of size %d.",
+		      " Options rejected.", result);
+               tftp_send_error(sockfd, sa, EOPTNEG, data->data_buffer,
+			       data->data_buffer_size);
+               if (data->trace)
+		    logger(LOG_DEBUG, "sent ERROR <code: %d, msg: %s>",
+			   EOPTNEG, tftp_errmsg[EOPTNEG]);
+               fclose(fp);
+	       return ERR;
+          }
+
           data->data_buffer_size = result + 4;
           data->data_buffer = realloc(data->data_buffer, data->data_buffer_size);
 
@@ -559,11 +614,16 @@
           logger(LOG_INFO, "blksize option -> %d", result);
      }
 
+     /* multicast option */
+     if (data->tftp_options[OPT_MULTICAST].specified &&
+	 data->tftp_options[OPT_MULTICAST].enabled && !convert)
+     {
      /* Verify that the file can be sent in 2^16 block of BLKSIZE octets */
      if ((file_stat.st_size / (data->data_buffer_size - 4)) > 65535)
      {
           tftp_send_error(sockfd, sa, EUNDEF, data->data_buffer, data->data_buffer_size);
-          logger(LOG_NOTICE, "Requested file to big, increase BLKSIZE");
+          logger(LOG_NOTICE, "Requested file too big, increase BLKSIZE, ",
+                 "cannot rollover in multicast transfer");
           if (data->trace)
                logger(LOG_DEBUG, "sent ERROR <code: %d, msg: %s>", EUNDEF,
                       tftp_errmsg[EUNDEF]);
@@ -571,10 +631,6 @@
           return ERR;
      }
 
-     /* multicast option */
-     if (data->tftp_options[OPT_MULTICAST].specified &&
-         data->tftp_options[OPT_MULTICAST].enabled && !convert)
-     {
           /*
            * Find a server with the same options to give up the client.
            */
@@ -649,10 +705,16 @@
                /* initialise multicast address structure */
                data->mcastaddr.imr_multiaddr.s_addr =
                     data->sa_mcast.sin_addr.s_addr;
-               data->mcastaddr.imr_interface.s_addr = htonl(INADDR_ANY); 
+
                setsockopt(data->sockfd, IPPROTO_IP, IP_MULTICAST_TTL, 
                           &data->mcast_ttl, sizeof(data->mcast_ttl));
                
+               logger(LOG_DEBUG, "Multicast interface = %s",
+                      inet_ntoa(data->mcastaddr.imr_interface)); 
+               setsockopt(data->sockfd, IPPROTO_IP, IP_MULTICAST_IF,
+			  &(data->mcastaddr.imr_interface.s_addr),
+			  sizeof(data->mcastaddr.imr_interface.s_addr));
+
                /* set options data for OACK */
                opt_set_multicast(data->tftp_options, data->mc_addr,
                                  data->mc_port, 1);
@@ -661,7 +723,7 @@
             
                /* the socket must be unconnected for multicast */
                sa->sin_family = AF_UNSPEC;
-               connect(sockfd, (struct sockaddr *)sa, sizeof(sa));
+               connect(sockfd, (struct sockaddr *)sa, sizeof(*sa));
 
                /* set multicast flag */
                multicast = 1;
@@ -669,6 +731,11 @@
                tftpd_clientlist_ready(data);
           }
      }
+     if ((file_stat.st_size / (data->data_buffer_size - 4)) > 65535)
+     {
+          logger(LOG_NOTICE, "Requested file bigger than tftp is designed to ",
+		 "handle, attempting rollover, but not officially in a tftp spec");
+     }
 
      /* copy options to local structure, used when falling back a client to slave */
      memcpy(options, data->tftp_options, sizeof(options));
@@ -706,10 +773,14 @@
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
+               {
+		    if (data->trace)
+                         logger(LOG_DEBUG, "sent OACK <%s>", string);
+               }
                state = S_WAIT_PACKET;
                break;
           case S_SEND_DATA:
@@ -725,18 +796,24 @@
 
                if (multicast)
                {
-                    tftp_send_data(sockfd, &data->sa_mcast,
-                                   block_number + 1, data_size,
-                                   data->data_buffer);
+                    result = tftp_send_data(sockfd, &data->sa_mcast,
+                                            block_number + 1, data_size,
+                                            data->data_buffer);
+                    client_info->bytes_sent += data_size-4;
                }
                else
                {
-                    tftp_send_data(sockfd, sa, block_number + 1,
-                                   data_size, data->data_buffer);
+                    result = tftp_send_data(sockfd, sa, block_number + 1,
+                                            data_size, data->data_buffer);
                }
-               if (data->trace)
-                    logger(LOG_DEBUG, "sent DATA <block: %d, size %d>",
-                           block_number + 1, data_size - 4);
+
+               if (result == OK)
+	       {
+                    if (data->trace)
+                         logger(LOG_DEBUG, "sent DATA <block: %d, size %d>",
+                                block_number + 1, data_size - 4);
+               }
+               time(&last_send_time); 
                state = S_WAIT_PACKET;
                break;
           case S_WAIT_PACKET:
@@ -746,12 +823,14 @@
                switch (result)
                {
                case GET_TIMEOUT:
-                    number_of_timeout++;
+		    client_info->number_of_timeout++;
                     
-                    if (number_of_timeout > NB_OF_RETRY)
+                    if (client_info->number_of_timeout > NB_OF_RETRY)
                     {
-                         logger(LOG_INFO, "client (%s) not responding",
-                                inet_ntoa(client_info->client.sin_addr));
+                         logger(LOG_INFO, "client (%s) not responding.",
+                                " state=%d block_number=%d",
+                                inet_ntoa(client_info->client.sin_addr),
+                                timeout_state,block_number);
                          state = S_END;
                     }
                     else
@@ -779,7 +858,8 @@
                                    /* Proceed normally with the next client,
                                       going to OACK state */
                                    logger(LOG_INFO,
-                                          "Serving next client: %s:%d",
+                                          "Serving next client after timeout: state=%d, block_number=%d: %s:%d",
+                                          timeout_state,block_number, 
                                           inet_ntoa(client_info->client.sin_addr),
                                           ntohs(client_info->client.sin_port));
                                    sa = &client_info->client;
@@ -796,7 +876,9 @@
                                    break;
                               }
                          }
-                         logger(LOG_WARNING, "timeout: retrying...");
+                         logger(LOG_WARNING, "timeout: retrying... state=%d,",
+                                " block_number=%d", timeout_state,
+                                block_number);
                          state = timeout_state;
                     }
                     break;
@@ -811,7 +893,13 @@
                                * If this is an ACK for the last block, mark this client as
                                * done
                                */
-                              if ((last_block != -1) && (block_number > last_block))
+                             logger(LOG_DEBUG,
+                                    "received ACK <block: %d> from wrong client: %s:%d",
+                                     ntohs(tftphdr->th_block),
+                                     inet_ntoa(from.sin_addr),
+                                     ntohs(from.sin_port));
+
+			      if ((last_block != -1) && (ntohs(tftphdr->th_block) > last_block))
                               {
                                    if (tftpd_clientlist_done(data, NULL, &from) == 1)
                                         logger(LOG_DEBUG, "client done <%s>",
@@ -851,8 +939,33 @@
                          }
                     }
                     /* The ACK is from the current client */
-                    number_of_timeout = 0;
-                    block_number = ntohs(tftphdr->th_block);
+		    client_info->number_of_timeout = 0;
+		    int ACK_block_number = ntohs(tftphdr->th_block);
+		    if (ACK_block_number == client_info->last_ack)
+		    {
+			 /* duplicate ACK, ignore */
+			 time_t now;
+			 time(&now);
+			 /* if a timeout has occurred, resend last block */
+			 if ((now-last_send_time) > timeout)
+			 {
+                              state = S_SEND_DATA;
+			      logger(LOG_DEBUG, "Duplicate ACK packet discarded <%d>, timeout. Resend last block.", ACK_block_number);
+                         }
+			 else
+			 {
+			      logger(LOG_DEBUG, "Duplicate ACK packet discarded <%d>.", ACK_block_number);
+                         }
+			 break;
+                    }
+
+		    client_info->last_ack = ACK_block_number;
+
+		    if (block_number < 65534)
+			 block_number = ACK_block_number;
+                    else
+			 block_number++;
+
                     if (data->trace)
                          logger(LOG_DEBUG, "received ACK <block: %d>",
                                 block_number);
@@ -932,10 +1045,16 @@
                }
                break;
           case S_END:
+               total_bytes_sent += client_info->bytes_sent;
                if (multicast)
                {
                     logger(LOG_DEBUG, "End of multicast transfer");
+                    logger(LOG_INFO,
+                           "Bytes sent while this client was master: %d",
+                           client_info->bytes_sent);
+
                     /* mark the current client done */
+                    clients_served++;
                     tftpd_clientlist_done(data, client_info, NULL);
                     /* Look if there is another client to serve. We lock list of
                        client to make sure no other thread try to add clients in
@@ -948,13 +1067,20 @@
                                 ntohs(client_info->client.sin_port));
                          /* client is a new client structure */
                          sa =  &client_info->client;
-                         /* nedd to send an oack to that client */
+                         /* send an oack to that client */
                          state = S_SEND_OACK;                
                          fseek(fp, 0, SEEK_SET);
                     }
                     else
                     {
-                         logger(LOG_INFO, "No more client, end of tranfers");
+                         int fs = file_stat.st_size;
+                         int blksze = (data->data_buffer_size - 4);
+                         int ttlblks = fs / blksze;
+                         int blksretry = (total_bytes_sent-file_stat.st_size) / blksze;
+                         logger(LOG_INFO, "No more client, end of tranfers. %d clients served", clients_served);
+                         logger(LOG_INFO, "Bytes saved over unicast: %ld", (clients_served*file_stat.st_size) - total_bytes_sent);
+                         logger(LOG_INFO, "File size: %d, total data bytes sent %d", file_stat.st_size, total_bytes_sent);
+                         logger(LOG_INFO, "Block re-sent: %d of %d = %f percent", blksretry, ttlblks, ((float)blksretry/(float)ttlblks) * 100);
                          fclose(fp);
                          return OK;
                     }
