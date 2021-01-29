--- src/wayland-server.c.orig	2020-12-21 10:17:10 UTC
+++ src/wayland-server.c
@@ -25,6 +25,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdbool.h>
 #include <stdlib.h>
 #include <stdint.h>
@@ -44,6 +46,15 @@
 #include <sys/file.h>
 #include <sys/stat.h>
 
+#ifdef HAVE_SYS_UCRED_H
+#include <sys/param.h>
+#include <sys/ucred.h>
+#ifndef SOL_LOCAL
+/* DragonFly or FreeBSD < 12.2 */
+#define SOL_LOCAL 0
+#endif
+#endif
+
 #include "wayland-util.h"
 #include "wayland-private.h"
 #include "wayland-server-private.h"
@@ -79,7 +86,13 @@ struct wl_client {
 	struct wl_list link;
 	struct wl_map objects;
 	struct wl_priv_signal destroy_signal;
+#ifdef HAVE_SYS_UCRED_H
+	/* FreeBSD */
+	struct xucred xucred;
+#else
+	/* Linux */
 	struct ucred ucred;
+#endif
 	int error;
 	struct wl_priv_signal resource_created_signal;
 };
@@ -315,7 +328,17 @@ wl_resource_post_error(struct wl_resource *resource,
 static void
 destroy_client_with_error(struct wl_client *client, const char *reason)
 {
+#ifdef HAVE_SYS_UCRED_H
+	/* FreeBSD */
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1300030
+	wl_log("%s (pid %u)\n", reason, client->xucred.cr_pid);
+#else
+	wl_log("%s\n", reason);
+#endif
+#else
+	/* Linux */
 	wl_log("%s (pid %u)\n", reason, client->ucred.pid);
+#endif
 	wl_client_destroy(client);
 }
 
@@ -529,10 +552,20 @@ wl_client_create(struct wl_display *display, int fd)
 	if (!client->source)
 		goto err_client;
 
+#if defined(SO_PEERCRED)
+	/* Linux */
 	len = sizeof client->ucred;
 	if (getsockopt(fd, SOL_SOCKET, SO_PEERCRED,
 		       &client->ucred, &len) < 0)
 		goto err_source;
+#elif defined(LOCAL_PEERCRED)
+	/* FreeBSD */
+	len = sizeof client->xucred;
+	if (getsockopt(fd, SOL_LOCAL, LOCAL_PEERCRED,
+		       &client->xucred, &len) < 0 ||
+		       client->xucred.cr_version != XUCRED_VERSION)
+		goto err_source;
+#endif
 
 	client->connection = wl_connection_create(fd);
 	if (client->connection == NULL)
@@ -586,12 +619,28 @@ WL_EXPORT void
 wl_client_get_credentials(struct wl_client *client,
 			  pid_t *pid, uid_t *uid, gid_t *gid)
 {
+#ifdef HAVE_SYS_UCRED_H
+	/* DragonFly or FreeBSD */
 	if (pid)
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1300030
+		/* Since https://cgit.freebsd.org/src/commit/?id=c5afec6e895a */
+		*pid = client->xucred.cr_pid;
+#else
+		*pid = 0;
+#endif
+	if (uid)
+		*uid = client->xucred.cr_uid;
+	if (gid)
+		*gid = client->xucred.cr_gid;
+#else
+	/* Linux */
+	if (pid)
 		*pid = client->ucred.pid;
 	if (uid)
 		*uid = client->ucred.uid;
 	if (gid)
 		*gid = client->ucred.gid;
+#endif
 }
 
 /** Get the file descriptor for the client
