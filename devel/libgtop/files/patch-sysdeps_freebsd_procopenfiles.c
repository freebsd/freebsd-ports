--- sysdeps/freebsd/procopenfiles.c.orig	2014-10-12 07:17:26 UTC
+++ sysdeps/freebsd/procopenfiles.c
@@ -322,12 +322,21 @@ glibtop_get_proc_open_files_s (glibtop *server, glibto
 				struct sockaddr_un *sun;
 
 				entry.type = GLIBTOP_FILE_TYPE_LOCALSOCKET;
+/* 64bit inodes */
+#if __FreeBSD_version >= 1200031
+				sun = (struct sockaddr_un *)&kif->kf_un.kf_sock.kf_sa_local;
+#else
 				sun = (struct sockaddr_un *)&kif->kf_sa_local;
+#endif
 
 				if (sun->sun_path[0]) {
 					char *addrstr;
 
+#if __FreeBSD_version >= 1200031
+					addrstr = addr_to_string(&kif->kf_un.kf_sock.kf_sa_local);
+#else
 					addrstr = addr_to_string(&kif->kf_sa_local);
+#endif
 					g_strlcpy(entry.info.localsock.name,
 						  addrstr,
 						  sizeof(entry.info.localsock.name));
@@ -335,7 +344,11 @@ glibtop_get_proc_open_files_s (glibtop *server, glibto
 				} else {
 					char *addrstr;
 
+#if __FreeBSD_version >= 1200031
+					addrstr = addr_to_string(&kif->kf_un.kf_sock.kf_sa_peer);
+#else
 					addrstr = addr_to_string(&kif->kf_sa_peer);
+#endif
 					g_strlcpy(entry.info.localsock.name,
 						  addrstr,
 						  sizeof(entry.info.localsock.name));
@@ -349,12 +362,20 @@ glibtop_get_proc_open_files_s (glibtop *server, glibto
 					entry.type = GLIBTOP_FILE_TYPE_INETSOCKET;
 				else
 					entry.type = GLIBTOP_FILE_TYPE_INET6SOCKET;
+#if __FreeBSD_version >= 1200031
+				addrstr = addr_to_string(&kif->kf_un.kf_sock.kf_sa_peer);
+#else
 				addrstr = addr_to_string(&kif->kf_sa_peer);
+#endif
 				g_strlcpy(entry.info.sock.dest_host,
 					  addrstr,
 					  sizeof(entry.info.sock.dest_host));
 				g_free(addrstr);
+#if __FreeBSD_version >= 1200031
+				entry.info.sock.dest_port = addr_to_port(&kif->kf_un.kf_sock.kf_sa_peer);
+#else
 				entry.info.sock.dest_port = addr_to_port(&kif->kf_sa_peer);
+#endif
 			}
 		} else if (kif->kf_type == KF_TYPE_PIPE) {
 			entry.type = GLIBTOP_FILE_TYPE_PIPE;
