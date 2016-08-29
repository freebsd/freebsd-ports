--- rxstack.c.orig	2014-06-22 03:45:14 UTC
+++ rxstack.c
@@ -1575,7 +1575,7 @@ int rxstack_pull_line_off_queue( Client 
             if ( q->oldest == NULL )
                q->oldest = client;
             rc = RXSTACK_WAITING; /* waiting */
-            DEBUGDUMP(printf("waiting until %ld.%d\n", client->deadline.seconds,client->deadline.milli ););
+            DEBUGDUMP(printf("waiting until %ld.%d\n", (long) client->deadline.seconds,client->deadline.milli ););
          }
       }
    }
@@ -1854,7 +1854,7 @@ int rxstack_process_websockets_headers( 
    key[end-start] = '\0';
 
    start = strstr(ws_headers, "\r\n\r\n");
-   DEBUGDUMP(printf("end of headers at %x: [%s]\n",start,start ););
+   DEBUGDUMP(printf("end of headers at %x: [%s]\n",(unsigned int) start,start ););
 
    /*
     * Generate our response key
@@ -2958,7 +2958,7 @@ int rxstack_doit( )
          rc = 0 ; /* already timed out */
       if ( ( rc == -1 ) || ( rc > DEFAULT_WAKEUP ) )
          rc = DEFAULT_WAKEUP ;
-      DEBUGDUMP(printf("), to=%d) ms at %ld,%03d\n", rc, now.seconds, now.milli ););
+      DEBUGDUMP(printf("), to=%d) ms at %ld,%03d\n", rc, (long) now.seconds, now.milli ););
 #if defined(HAVE_POLL) && (defined(HAVE_POLL_H) || defined(HAVE_SYS_POLL_H))
       rc = poll( pd, poll_cnt, rc ) ;
 #else
@@ -2967,7 +2967,7 @@ int rxstack_doit( )
       rc = select( max_sock + 1, &ready, (fd_set *)0, (fd_set *)0, &to ) ;
 #endif
       now = get_now( ) ;
-      DEBUGDUMP(printf("****** after waiting(), rc=%d at %ld,%03d\n", rc, now.seconds, now.milli ););
+      DEBUGDUMP(printf("****** after waiting(), rc=%d at %ld,%03d\n", rc, (long) now.seconds, now.milli ););
       if ( rc < 0 )
       {
          if ( os_errno != EINTR ) /* Win32 doesn't know about it ? */
