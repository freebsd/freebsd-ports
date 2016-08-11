--- src/libnml/buffer/recvn.c.orig	2016-06-25 02:19:12 UTC
+++ src/libnml/buffer/recvn.c
@@ -186,7 +186,7 @@ int recvn(int fd, void *vptr, int n, int
 		}
 		nrecv = 0;
 	    } else if (nrecv == 0) {
-		rcs_print_error("recvn: Premature EOF recieved.\n");
+		rcs_print_error("recvn: Premature EOF received, errno %d, bytes to read %d, flags %x.\n", errno, bytes_to_read, flags);
 		return (-2);
 	    }
 	}
