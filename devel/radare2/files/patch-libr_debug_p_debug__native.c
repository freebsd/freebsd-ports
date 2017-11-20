--- libr/debug/p/debug_native.c.orig	2017-11-13 19:15:44 UTC
+++ libr/debug/p/debug_native.c
@@ -1620,6 +1620,7 @@ static RList *r_debug_desc_native_list (
 		case KF_TYPE_VNODE: type = 'v'; break;
 		case KF_TYPE_SOCKET:
 			type = 's';
+#if __FreeBSD_version < 1200031
 			if (kve->kf_sock_domain == AF_LOCAL) {
 				struct sockaddr_un *sun =
 					(struct sockaddr_un *)&kve->kf_sa_local;
@@ -1633,6 +1634,21 @@ static RList *r_debug_desc_native_list (
 				addr_to_string (&kve->kf_sa_peer, path + strlen (path),
 						sizeof (path));
 			}
+#else
+			if (kve->kf_sock_domain == AF_LOCAL) {
+				struct sockaddr_un *sun =
+					(struct sockaddr_un *)&kve->kf_un.kf_sock.kf_sa_local;;
+				if (sun->sun_path[0] != 0)
+					addr_to_string (&kve->kf_un.kf_sock.kf_sa_local, path, sizeof(path));
+				else
+					addr_to_string (&kve->kf_un.kf_sock.kf_sa_peer, path, sizeof(path));
+			} else {
+				addr_to_string (&kve->kf_un.kf_sock.kf_sa_local, path, sizeof(path));
+				strcat (path, " ");
+				addr_to_string (&kve->kf_un.kf_sock.kf_sa_peer, path + strlen (path),
+						sizeof (path));
+			}	
+#endif
 			str = path;
 			break;
 		case KF_TYPE_PIPE: type = 'p'; break;
