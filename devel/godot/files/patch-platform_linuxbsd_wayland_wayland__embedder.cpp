--- platform/linuxbsd/wayland/wayland_embedder.cpp.orig	2026-01-25 12:41:41 UTC
+++ platform/linuxbsd/wayland/wayland_embedder.cpp
@@ -38,6 +38,22 @@
 
 #ifdef __FreeBSD__
 #include <dev/evdev/input-event-codes.h>
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+
+/** if CMSG_ALIGN is not defined on this platform, a workaround */
+#ifndef CMSG_ALIGN
+#  ifdef __CMSG_ALIGN
+#    define CMSG_ALIGN(n) __CMSG_ALIGN(n)
+#  elif defined(CMSG_DATA_ALIGN)
+#    define CMSG_ALIGN _CMSG_DATA_ALIGN
+#  else
+#    define CMSG_ALIGN(len) (((len)+sizeof(long)-1) & ~(sizeof(long)-1))
+#  endif
+#endif
+
 #else
 // Assume Linux.
 #include <linux/input-event-codes.h>
@@ -2869,15 +2885,27 @@ void WaylandEmbedder::handle_fd(int p_fd, int p_revent
 		int new_fd = accept(proxy_socket, nullptr, nullptr);
 		ERR_FAIL_COND_MSG(new_fd == -1, "Failed to accept client.");
 
+#if defined(__FreeBSD__)
+		struct xucred cred = {};
+#else
 		struct ucred cred = {};
+#endif
 		socklen_t cred_size = sizeof cred;
+#if defined(__FreeBSD__)
+		getsockopt(new_fd, SOL_LOCAL, LOCAL_PEERCRED, &cred, &cred_size);
+#else
 		getsockopt(new_fd, SOL_SOCKET, SO_PEERCRED, &cred, &cred_size);
+#endif
 
 		Client &client = clients.insert_new(new_fd, {})->value;
 
 		client.embedder = this;
 		client.socket = new_fd;
+#if defined(__FreeBSD__)
+		client.pid = cred.cr_pid;
+#else
 		client.pid = cred.pid;
+#endif
 
 		client.global_ids[DISPLAY_ID] = Client::GlobalIdInfo(DISPLAY_ID, nullptr);
 		client.local_ids[DISPLAY_ID] = DISPLAY_ID;
@@ -2900,7 +2928,11 @@ void WaylandEmbedder::handle_fd(int p_fd, int p_revent
 				main_client->new_fake_object(new_local_id, &godot_embedded_client_interface, 1, eclient_data);
 
 				// godot_embedding_compositor::client(nu)
+#if defined(__FreeBSD__)
+				send_wayland_message(main_client->socket, local_id, 0, { new_local_id, (uint32_t)cred.cr_pid });
+#else
 				send_wayland_message(main_client->socket, local_id, 0, { new_local_id, (uint32_t)cred.pid });
+#endif
 			}
 		}
 
