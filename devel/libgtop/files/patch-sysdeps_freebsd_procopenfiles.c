--- sysdeps/freebsd/procopenfiles.c.orig	2007-07-01 09:14:23.000000000 -0400
+++ sysdeps/freebsd/procopenfiles.c	2008-02-10 02:45:20.000000000 -0500
@@ -28,6 +28,13 @@
 #include <glibtop/error.h>
 #include <glibtop/procopenfiles.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/un.h>
+#include <sys/user.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <string.h>
 #include <stdlib.h>
 
@@ -46,6 +53,63 @@ _glibtop_init_proc_open_files_s (glibtop
 	server->sysdeps.proc_open_files = _glibtop_sysdeps_proc_open_files;
 }
 
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+static char *
+addr_to_string(struct sockaddr_storage *ss)
+{
+	char *buffer;
+	char buffer2[INET6_ADDRSTRLEN];
+	struct sockaddr_in6 *sin6;
+	struct sockaddr_in *sin;
+	struct sockaddr_un *sun;
+
+	switch (ss->ss_family) {
+		case AF_LOCAL:
+			sun = (struct sockaddr_un *)ss;
+			if (strlen(sun->sun_path) == 0)
+				buffer = g_strdup("-");
+			else
+				buffer = g_strdup(sun->sun_path);
+			break;
+		case AF_INET:
+			sin = (struct sockaddr_in *)ss;
+			buffer = g_strdup(inet_ntoa(sin->sin_addr));
+			break;
+		case AF_INET6:
+			sin6 = (struct sockaddr_in6 *)ss;
+			if (inet_ntop(AF_INET6, &sin6->sin6_addr, buffer2,
+			    sizeof(buffer2)) != NULL)
+				buffer = g_strdup(buffer2);
+			else
+				buffer = g_strdup("-");
+			break;
+	}
+
+	return buffer;
+}
+
+static int
+addr_to_port(struct sockaddr_storage *ss)
+{
+	int port;
+	struct sockaddr_in6 *sin6;
+	struct sockaddr_in *sin;
+
+	switch (ss->ss_family) {
+		case AF_INET:
+			sin = (struct sockaddr_in *)ss;
+			port = ntohs(sin->sin_port);
+			break;
+		case AF_INET6:
+			sin6 = (struct sockaddr_in6 *)ss;
+			port = ntohs(sin6->sin6_port);
+			break;
+	}
+
+	return port;
+}
+#else
+
 static GArray *
 parse_output(const char *output) {
 	GArray *entries;
@@ -159,21 +223,105 @@ parse_output(const char *output) {
 
 	return entries;
 }
+#endif
 
 glibtop_open_files_entry *
 glibtop_get_proc_open_files_s (glibtop *server, glibtop_proc_open_files *buf,	pid_t pid)
 {
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+	struct kinfo_file *freep, *kif;
+	int name[4];
+	size_t len;
+	int i;
+#else
 	char *output;
+#endif
 	GArray *entries;
 
 	memset(buf, 0, sizeof (glibtop_proc_open_files));
 
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+	name[0] = CTL_KERN;
+	name[1] = KERN_PROC;
+	name[2] = KERN_PROC_FILEDESC;
+	name[3] = pid;
+
+	if (sysctl(name, 4, NULL, &len, NULL, 0) < 0)
+		return NULL;
+
+	freep = kif = g_malloc(len);
+	if (sysctl(name, 4, kif, &len, NULL, 0) < 0) {
+		g_free(freep);
+		return NULL;
+	}
+
+	entries = g_array_new(FALSE, FALSE, sizeof(glibtop_open_files_entry));
+
+	for (i = 0; i < len / sizeof(*kif); i++, kif++) {
+		glibtop_open_files_entry entry = {0};
+
+		if (kif->kf_fd < 0)
+			continue;
+
+		if (kif->kf_type == KF_TYPE_SOCKET) {
+			if (kif->kf_sock_domain == AF_LOCAL) {
+				struct sockaddr_un *sun;
+
+				entry.type = GLIBTOP_FILE_TYPE_LOCALSOCKET;
+				sun = (struct sockaddr_un *)&kif->kf_sa_local;
+
+				if (sun->sun_path[0]) {
+					char *addrstr;
+
+					addrstr = addr_to_string(&kif->kf_sa_local);
+					g_strlcpy(entry.info.localsock.name,
+						  addrstr,
+						  sizeof(entry.info.localsock.name));
+					g_free(addrstr);
+				} else {
+					char *addrstr;
+
+					addrstr = addr_to_string(&kif->kf_sa_peer);
+					g_strlcpy(entry.info.localsock.name,
+						  addrstr,
+						  sizeof(entry.info.localsock.name));
+					g_free(addrstr);
+				}
+			} else if (kif->kf_sock_domain == AF_INET ||
+				   kif->kf_sock_domain == AF_INET6) {
+				char *addrstr;
+
+				entry.type = GLIBTOP_FILE_TYPE_INETSOCKET;
+				addrstr = addr_to_string(&kif->kf_sa_peer);
+				g_strlcpy(entry.info.sock.dest_host,
+					  addrstr,
+					  sizeof(entry.info.sock.dest_host));
+				g_free(addrstr);
+				entry.info.sock.dest_port = addr_to_port(&kif->kf_sa_peer);
+			}
+		} else if (kif->kf_type == KF_TYPE_PIPE) {
+			entry.type = GLIBTOP_FILE_TYPE_PIPE;
+		} else if (kif->kf_type == KF_TYPE_VNODE) {
+			entry.type = GLIBTOP_FILE_TYPE_FILE;
+			g_strlcpy(entry.info.file.name, kif->kf_path,
+				  sizeof(entry.info.file.name));
+		} else
+			continue;
+
+		entry.fd = kif->kf_fd;
+
+		g_array_append_val(entries, entry);
+	}
+	g_free(freep);
+#else
+
 	output = execute_lsof(pid);
 	if (output == NULL) return NULL;
 
 	entries = parse_output(output);
 
 	g_free(output);
+#endif
 
 	buf->flags = _glibtop_sysdeps_proc_open_files;
 	buf->number = entries->len;
