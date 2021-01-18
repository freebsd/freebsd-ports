--- rxstack.c.orig	2019-10-06 06:19:40 UTC
+++ rxstack.c
@@ -1585,7 +1585,7 @@ int rxstack_pull_line_off_queue( Client *client, stren
             if ( q->oldest == NULL )
                q->oldest = client;
             rc = RXSTACK_WAITING; /* waiting */
-            DEBUGDUMP(printf("waiting until %ld.%d\n", client->deadline.seconds,client->deadline.milli ););
+            DEBUGDUMP(printf("waiting until %ld.%d\n", (long) client->deadline.seconds,client->deadline.milli ););
          }
       }
    }
@@ -1914,7 +1914,7 @@ int rxstack_process_websockets_headers( Client *client
    key[end-start] = '\0';
 
    start = strstr(ws_headers, "\r\n\r\n");
-   DEBUGDUMP(printf("end of headers at %x: [%s]\n",start,start ););
+   DEBUGDUMP(printf("end of headers at %x: [%s]\n",(unsigned int) start,start ););
 
    /*
     * Generate our response key
@@ -1966,11 +1966,11 @@ int decode_ws_payload( unsigned char *src, size_t srcl
       // Find beginning of next frame. First time hdr_length, masked and
       // payload_length are zero
       frame += hdr_length + 4*masked + payload_length;
-      DEBUGDUMP(printf("frame[0..3]: 0x%x 0x%x 0x%x 0x%x (tot: %d)\n",(unsigned char) frame[0],(unsigned char) frame[1],(unsigned char) frame[2],(unsigned char) frame[3], srclength););
+      DEBUGDUMP(printf("frame[0..3]: 0x%x 0x%x 0x%x 0x%x (tot: %d)\n",(unsigned char) frame[0],(unsigned char) frame[1],(unsigned char) frame[2],(unsigned char) frame[3], (int) srclength););
 
       if (frame > src + srclength)
       {
-         DEBUGDUMP(printf("Truncated frame from client, need %d more bytes\n",frame - (src + srclength)););
+         DEBUGDUMP(printf("Truncated frame from client, need %d more bytes\n", (int) (frame - (src + srclength))););
          break;
       }
       remaining = (src + srclength) - frame;
@@ -2010,7 +2010,7 @@ int decode_ws_payload( unsigned char *src, size_t srcl
       {
          continue;
       }
-      DEBUGDUMP(printf("    payload_length: %u, raw remaining: %u, , hdr_length: %d, opcode %d\n",payload_length, remaining,hdr_length, *opcode););
+      DEBUGDUMP(printf("    payload_length: %u, raw remaining: %u, , hdr_length: %d, opcode %d\n",payload_length, (int) remaining,hdr_length, *opcode););
       payload = frame + hdr_length + 4*masked;
 
       if (*opcode != 1 && *opcode != 2)
@@ -3041,7 +3041,7 @@ int rxstack_doit( )
          rc = 0 ; /* already timed out */
       if ( ( rc == -1 ) || ( rc > DEFAULT_WAKEUP ) )
          rc = DEFAULT_WAKEUP ;
-      DEBUGDUMP(printf("), to=%d) ms at %ld,%03d\n", rc, now.seconds, now.milli ););
+      DEBUGDUMP(printf("), to=%d) ms at %ld,%03d\n", rc, (long) now.seconds, now.milli ););
 #if defined(HAVE_POLL) && (defined(HAVE_POLL_H) || defined(HAVE_SYS_POLL_H))
       rc = poll( pd, poll_cnt, rc ) ;
 #else
@@ -3050,7 +3050,7 @@ int rxstack_doit( )
       rc = select( max_sock + 1, &ready, (fd_set *)0, (fd_set *)0, &to ) ;
 #endif
       now = get_now( ) ;
-      DEBUGDUMP(printf("****** after waiting(), rc=%d at %ld,%03d\n", rc, now.seconds, now.milli ););
+      DEBUGDUMP(printf("****** after waiting(), rc=%d at %ld,%03d\n", rc, (long) now.seconds, now.milli ););
       if ( rc < 0 )
       {
          if ( os_errno != EINTR ) /* Win32 doesn't know about it ? */
