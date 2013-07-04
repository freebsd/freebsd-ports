--- src/backend/entangle-device-manager.c.orig	2013-03-13 05:23:35.000000000 +0800
+++ src/backend/entangle-device-manager.c	2013-07-04 20:02:19.000000000 +0800
@@ -20,13 +20,19 @@
 
 #include <config.h>
 
-#include <string.h>
-#include <stdio.h>
-
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#include <sys/un.h>
+#include <glib.h>
+#include <unistd.h>
+#else
 #define G_UDEV_API_IS_SUBJECT_TO_CHANGE
 #ifdef G_UDEV_API_IS_SUBJECT_TO_CHANGE
 #include <gudev/gudev.h>
 #endif
+#endif
+#include <string.h>
+#include <stdio.h>
 
 #include "entangle-debug.h"
 #include "entangle-device-manager.h"
@@ -35,7 +41,11 @@
     (G_TYPE_INSTANCE_GET_PRIVATE((obj), ENTANGLE_TYPE_DEVICE_MANAGER, EntangleDeviceManagerPrivate))
 
 struct _EntangleDeviceManagerPrivate {
+#if defined(__linux__)
     GUdevClient *ctx;
+#elif defined(__FreeBSD__)
+    int efd;
+#endif
 };
 
 G_DEFINE_TYPE(EntangleDeviceManager, entangle_device_manager, G_TYPE_OBJECT);
@@ -47,8 +57,13 @@ static void entangle_device_manager_fina
     EntangleDeviceManagerPrivate *priv = manager->priv;
     ENTANGLE_DEBUG("Finalize manager");
 
+#if defined(__linux__)
     if (priv->ctx)
         g_object_unref(priv->ctx);
+#elif defined(__FreeBSD__)
+    if (priv->efd)
+        close(priv->efd);
+#endif
 
     G_OBJECT_CLASS (entangle_device_manager_parent_class)->finalize (object);
 }
@@ -85,6 +100,7 @@ static void entangle_device_manager_clas
 }
 
 
+#if defined(__linux__)
 static void do_udev_event(GUdevClient *client G_GNUC_UNUSED,
                           const char *action,
                           GUdevDevice *dev,
@@ -126,6 +142,91 @@ static void do_udev_event(GUdevClient *c
     }
     g_free(port);
 }
+#elif defined(__FreeBSD__)
+static void devd_init(EntangleDeviceManager *manager);
+
+static gboolean do_devd_event(GIOChannel *source,
+                              GIOCondition condition,
+                              gpointer user_data)
+{
+    EntangleDeviceManager *manager = user_data;
+    char *event, *cutoff;
+    gsize end;
+    GIOStatus status;
+
+    status = g_io_channel_read_line(source, &event, NULL, &end, NULL);
+
+    switch (status) {
+    case G_IO_STATUS_NORMAL:
+        event[end] = '\0';
+        if (strncmp(event + 1, "ugen", 4))
+            break;
+        if (!(cutoff = strchr(event + 5, ' ')))
+            break;
+        *cutoff = '\0';
+        if (*event == '+') {
+            g_signal_emit_by_name(manager, "device-added", event + 1);
+        } else if (*event == '-') {
+            g_signal_emit_by_name(manager, "device-removed", event + 1);
+        }
+        g_free(event);
+        break;
+    case G_IO_STATUS_EOF:
+    case G_IO_STATUS_AGAIN:
+        /*
+         * Apparently, devd(8) was reinited (restarted?).  Allocate
+         * new channel and teardown previous connection.
+         */
+        devd_init(manager);
+        if (manager->priv->efd > 0) {
+            int old_efd = g_io_channel_unix_get_fd(source);
+            g_io_channel_shutdown(source, FALSE, NULL);
+            close(old_efd);
+            return FALSE;
+        }
+        break;
+    case G_IO_STATUS_ERROR:
+    default:
+        /* XXX: what shall we do? */
+        break;
+    }
+    return TRUE;
+}
+
+
+static void devd_init(EntangleDeviceManager *manager)
+{
+    EntangleDeviceManagerPrivate *priv = manager->priv;
+    struct sockaddr_un addr;
+
+    priv->efd = socket(PF_UNIX, SOCK_STREAM, 0);
+    if (priv->efd == -1) {
+        perror("socket");
+        return;
+    }
+
+    addr.sun_family = AF_UNIX;
+    strncpy(addr.sun_path, "/var/run/devd.pipe", sizeof(addr.sun_path));
+
+    if (connect(priv->efd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
+        GIOChannel *channel = g_io_channel_unix_new(priv->efd);
+        g_io_add_watch(channel, G_IO_IN, do_devd_event, manager);
+        /*
+         * We can reduce the refcount here so that when the watch is
+         * removed, the channel will be destroyed.
+         */
+        g_io_channel_unref(channel);
+    } else {
+        /*
+         * XXX: we should probably spin for a while until connect()
+         * succeeds to get rid of the useless socket()/close() storm
+         * for a short period when devd(8) is not ready yet.
+         */
+        close(priv->efd);
+        priv->efd = -1;
+    }
+}
+#endif
 
 
 EntangleDeviceManager *entangle_device_manager_new(void)
@@ -138,6 +239,8 @@ static void entangle_device_manager_init
 {
     EntangleDeviceManagerPrivate *priv = manager->priv;
     GList *devs, *tmp;
+
+#if defined(__linux__)
     const gchar *const subsys[] = {
         "usb/usb_device", NULL,
     };
@@ -161,6 +264,12 @@ static void entangle_device_manager_init
     }
 
     g_list_free(devs);
+#elif defined(__FreeBSD__)
+
+    ENTANGLE_DEBUG("Init devd");
+
+    devd_init(manager);
+#endif
 }
 
 
