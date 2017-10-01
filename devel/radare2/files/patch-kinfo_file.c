--- libr/debug/p/debug_native.c.orig	2016-11-10 16:17:54 UTC
+++ libr/debug/p/debug_native.c
@@ -1487,15 +1487,15 @@ static RList *r_debug_desc_native_list (
 			type = 's';
 			if (kve->kf_sock_domain == AF_LOCAL) {
 				struct sockaddr_un *sun =
-					(struct sockaddr_un *)&kve->kf_sa_local;
+					(struct sockaddr_un *)&kve->kf_un.kf_sock.kf_sa_local;
 				if (sun->sun_path[0] != 0)
-					addr_to_string (&kve->kf_sa_local, path, sizeof(path));
+					addr_to_string (&kve->kf_un.kf_sock.kf_sa_local, path, sizeof(path));
 				else
-					addr_to_string (&kve->kf_sa_peer, path, sizeof(path));
+					addr_to_string (&kve->kf_un.kf_sock.kf_sa_peer, path, sizeof(path));
 			} else {
-				addr_to_string (&kve->kf_sa_local, path, sizeof(path));
+				addr_to_string (&kve->kf_un.kf_sock.kf_sa_local, path, sizeof(path));
 				strcat (path, " ");
-				addr_to_string (&kve->kf_sa_peer, path + strlen (path),
+				addr_to_string (&kve->kf_un.kf_sock.kf_sa_peer, path + strlen (path),
 						sizeof (path));
 			}
 			str = path;
