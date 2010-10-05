--- tftp_file.c.orig	2004-02-13 11:16:09.000000000 +0800
+++ tftp_file.c	2010-10-04 18:46:54.000000000 +0800
@@ -59,7 +59,7 @@
      unsigned int next_word;
 
      /* initial stuff */
-     next_hole = prev_hole + 1;
+     next_hole = 0; /*prev_hole + 1;*/
      next_word_no = next_hole / 32;
      next_bit_no  = next_hole % 32;
      next_word = bitmap[next_word_no];
@@ -150,7 +150,8 @@
      memset(&file_bitmap, 0, sizeof(file_bitmap));
 
      /* make sure the socket is not connected */
-     sa.sin_family = AF_UNSPEC;
+     memset(&sa, 0, sizeof(sa));
+     sa.sin_family = AF_INET;
      connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
      connected = 0;
 
@@ -238,9 +239,13 @@
                          tftp_find_bitmap_hole(prev_bitmap_hole, file_bitmap);
                     block_number = prev_bitmap_hole;
                }
-               if (data->trace)
-                    fprintf(stderr, "sent ACK <block: %d>\n", block_number);
-               tftp_send_ack(sockfd, &sa, block_number);
+               result = tftp_send_ack(sockfd, &sa, block_number);
+	       if (result == OK)
+	       {
+		    if (data->trace)
+			 fprintf(stderr, "sent ACK <block: %d>\n", 
+				 block_number);
+               }
                /* if we just ACK the last block we are done */
                if (block_number == last_block_number)
                     state = S_END;
@@ -627,7 +632,8 @@
      from.sin_addr.s_addr = 0;
 
      /* make sure the socket is not connected */
-     sa.sin_family = AF_UNSPEC;
+     memset(&sa, 0, sizeof(sa));
+     sa.sin_family = AF_INET;
      connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
      connected = 0;
 
@@ -761,7 +767,7 @@
                     /* if the socket if not connected, connect it */
                     if (!connected)
                     {
-                         //connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
+                         connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
                          connected = 1;
                     }
                     block_number = ntohs(tftphdr->th_block);
@@ -780,7 +786,7 @@
                     /* if the socket if not connected, connect it */
                     if (!connected)
                     {
-                         //connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
+                         connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
                          connected = 1;
                     }
                     state = S_OACK_RECEIVED;
