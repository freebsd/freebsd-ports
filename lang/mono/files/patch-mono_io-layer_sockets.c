--- mono/io-layer/sockets.c.orig	Sat May  7 14:54:36 2005
+++ mono/io-layer/sockets.c	Wed Oct 12 22:04:38 2005
@@ -846,35 +846,32 @@
 		return(SOCKET_ERROR);
 	}
 
-	if (command != FIONBIO &&
-	    command != FIONREAD &&
-	    command != SIOCATMARK) {
-		/* Not listed in the MSDN specs, but ioctl(2) returns
-		 * this if command is invalid
-		 */
-		WSASetLastError (WSAEINVAL);
-		return(SOCKET_ERROR);
-	}
-
+	switch(command){
+		case FIONBIO:
 #ifdef O_NONBLOCK
 	/* This works better than ioctl(...FIONBIO...) on Linux (it causes
 	 * connect to return EINPROGRESS, but the ioctl doesn't seem to)
 	 */
-	if (command == FIONBIO) {
-		ret = fcntl (fd, F_GETFL, 0);
-		if (ret != -1) {
-			if (*(gboolean *)arg) {
-				ret |= O_NONBLOCK;
-			} else {
-				ret &= ~O_NONBLOCK;
+			ret = fcntl(fd, F_GETFL, 0);
+			if (ret != -1) {
+				if (*(gboolean *)arg) {
+					ret |= O_NONBLOCK;
+				} else {
+					ret &= ~O_NONBLOCK;
+				}
+				ret = fcntl(fd, F_SETFL, ret);
 			}
-			ret = fcntl (fd, F_SETFL, ret);
-		}
-	} else
 #endif /* O_NONBLOCK */
-	{
-		ret = ioctl (fd, command, arg);
+			break;
+		case FIONREAD:
+		case SIOCATMARK:
+			ret = ioctl (fd, command, arg);
+			break;
+		default:
+			WSASetLastError (WSAEINVAL);
+			return(SOCKET_ERROR);
 	}
+
 	if (ret == -1) {
 		gint errnum = errno;
 #ifdef DEBUG
