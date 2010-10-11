--- tftp_file.c.orig	2010-10-11 11:21:54.000000000 +0800
+++ tftp_file.c	2010-10-11 11:27:01.000000000 +0800
@@ -59,7 +59,7 @@
      unsigned int next_word;
 
      /* initial stuff */
-     next_hole = prev_hole + 1;
+     next_hole = 0; /*prev_hole + 1;*/
      next_word_no = next_hole / 32;
      next_bit_no  = next_hole % 32;
      next_word = bitmap[next_word_no];
@@ -238,9 +238,13 @@
                          tftp_find_bitmap_hole(prev_bitmap_hole, file_bitmap);
                     block_number = prev_bitmap_hole;
                }
-               if (data->trace)
-                    fprintf(stderr, "sent ACK <block: %d>\n", block_number);
-               tftp_send_ack(sockfd, &sa, block_number);
+               result = tftp_send_ack(sockfd, &sa, block_number);
+               if (result == OK)
+               {
+                    if (data->trace)
+                         fprintf(stderr, "sent ACK <block: %d>\n", 
+                                 block_number);
+               }
                /* if we just ACK the last block we are done */
                if (block_number == last_block_number)
                     state = S_END;
@@ -484,6 +488,13 @@
                          sa_mcast.sin_family = AF_INET;
                          sa_mcast.sin_addr.s_addr = htonl(INADDR_ANY);
                          sa_mcast.sin_port = htons(mc_port);
+                         int yes = 1;
+                         if (setsockopt(mcast_sockfd, SOL_SOCKET,
+                                        SO_REUSEADDR, &yes, sizeof(yes)) < 0)
+                         {
+                              perror("setsockopt");
+                              exit(1);
+                         }
                          
                          if (bind(mcast_sockfd, (struct sockaddr *)&sa_mcast,
                                   sizeof(sa_mcast)) < 0)
