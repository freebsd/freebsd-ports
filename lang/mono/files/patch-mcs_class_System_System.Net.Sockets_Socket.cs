--- mcs/class/System/System.Net.Sockets/Socket.cs.orig	2008-11-01 00:35:55.000000000 -0300
+++ mcs/class/System/System.Net.Sockets/Socket.cs	2008-11-01 00:38:16.000000000 -0300
@@ -1552,7 +1552,7 @@
 			}
 
 			int error = 0;
-			if (!blocking) {
+//			if (!blocking) {
 				SocketAddress serial = end_point.Serialize ();
 				Connect_internal (socket, serial, out error);
 				if (error == 0) {
@@ -1564,15 +1564,16 @@
 					connected = false;
 					req.Complete (new SocketException (error), true);
 				}
-			}
+//			}
 
-			if (blocking || error == (int) SocketError.InProgress || error == (int) SocketError.WouldBlock) {
+/*			if (blocking || error == (int) SocketError.InProgress || error == (int) SocketError.WouldBlock) {
 				// continue asynch
 				connected = false;
 				Worker worker = new Worker (req);
 				SocketAsyncCall sac = new SocketAsyncCall (worker.Connect);
 				sac.BeginInvoke (null, req);
 			}
+*/
 
 			return(req);
 		}
