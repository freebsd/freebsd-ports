--- lib/ssluse.c.orig
+++ lib/ssluse.c
@@ -2608,13 +2608,19 @@ static ssize_t ossl_recv(struct connectdata *conn, /* connection data */
       *curlcode = CURLE_AGAIN;
       return -1;
     default:
-      /* openssl/ssl.h says "look at error stack/return value/errno" */
+      /* openssl/ssl.h for SSL_ERROR_SYSCALL says "look at error stack/return
+         value/errno" */
+      /* http://www.openssl.org/docs/crypto/ERR_get_error.html */
       sslerror = ERR_get_error();
-      failf(conn->data, "SSL read: %s, errno %d",
-            ERR_error_string(sslerror, error_buffer),
-            SOCKERRNO);
-      *curlcode = CURLE_RECV_ERROR;
-      return -1;
+      if((nread < 0) || sslerror) {
+        /* If the return code was negative or there actually is an error in the
+           queue */
+        failf(conn->data, "SSL read: %s, errno %d",
+              ERR_error_string(sslerror, error_buffer),
+              SOCKERRNO);
+        *curlcode = CURLE_RECV_ERROR;
+        return -1;
+      }
     }
   }
   return nread;
