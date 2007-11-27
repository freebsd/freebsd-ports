--- src/common/net/tcp_socket.cpp.orig	2007-11-27 15:14:42.000000000 +0100
+++ src/common/net/tcp_socket.cpp	2007-11-27 15:15:07.000000000 +0100
@@ -47,7 +47,7 @@
 		int recv_result = recv(socket, ((char*)buf)+bytes_done, bytes_left, 0);
 
 		if (recv_result < 0) {
-			logmsg(lt_error,"recv(%i,((char*)%x)+%i,%i,0); returned %i (%s)", socket,(int)buf,bytes_done,bytes_left,errno,strerror(errno));
+			logmsg(lt_error,"recv(%i,((char*)%x)+%i,%i,0); returned %i (%s)", socket,(size_t)buf,bytes_done,bytes_left,errno,strerror(errno));
 			// This is in most cases a critical error, so stop the loop
 			return ERROR_SOCKET;
 		} else if (recv_result > 0) {
@@ -75,7 +75,7 @@
 		int send_result = send(socket, ((char*)buf)+bytes_done, bytes_left, 0);
 
 		if (send_result < 0) {
-			logmsg(lt_error,"send(%i,((char*)%x)+%i,%i,0); returned %i (%s)", socket,(int)buf,bytes_done,bytes_left,errno,strerror(errno));
+			logmsg(lt_error,"send(%i,((char*)%x)+%i,%i,0); returned %i (%s)", socket,(size_t)buf,bytes_done,bytes_left,errno,strerror(errno));
 			// This is in most cases a critical error, so stop the loop
 			return ERROR_SOCKET;
 		} else if (send_result > 0) {
