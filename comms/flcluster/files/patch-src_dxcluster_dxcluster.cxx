--- src/dxcluster/dxcluster.cxx.orig	2017-09-22 15:49:18 UTC
+++ src/dxcluster/dxcluster.cxx
@@ -653,7 +653,6 @@ void parse_dxline(string dxbuffer)
 			isdigit(dxbuffer[p+3]) &&
 			(dxbuffer[p+4] == 'Z' || dxbuffer[4] == 'z')) {
 			dxc.time = dxbuffer.substr(p, 5);
-			if (dxbuffer.length() > p+5);
 			dxc.spotter_US_state = dxbuffer.substr(p+5);
 			dxbuffer.erase(p-1);
 		}
@@ -1178,8 +1177,7 @@ void parse_DXcluster_stream(string input
 			send_password();
 
 	}
-
-	if (keepalive > 0) {
+	if (progStatus.keepalive > 0) {
 		Fl::awake(restore_keepalive_box);
 		wait_for_keepalive = -1;
 	}
