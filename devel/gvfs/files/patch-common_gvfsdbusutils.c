https://bugzilla.gnome.org/show_bug.cgi?id=722411

--- common/gvfsdbusutils.c.orig	2014-05-25 17:43:08.000000000 +0200
+++ common/gvfsdbusutils.c	2014-05-25 17:43:08.000000000 +0200
@@ -0,0 +1,538 @@
+/* GIO - GLib Input, Output and Streaming Library
+ * 
+ * Copyright (C) 2006-2007 Red Hat, Inc.
+ *
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2 of the License, or (at your option) any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General
+ * Public License along with this library; if not, write to the
+ * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
+ * Boston, MA 02110-1301, USA.
+ *
+ * Author: Alexander Larsson <alexl@redhat.com>
+ */
+
+#include <config.h>
+
+#include <stdlib.h>
+#include <string.h>
+
+#include <glib/gi18n-lib.h>
+#include <gvfsdbusutils.h>
+#include <gio/gio.h>
+
+static void
+_g_dbus_oom (void)
+{
+  g_error ("DBus failed with out of memory error");
+}
+
+/*************************************************************************
+ *             Helper fd source                                          *
+ ************************************************************************/
+
+typedef struct 
+{
+  GSource source;
+  GPollFD pollfd;
+  GCancellable *cancellable;
+  gulong cancelled_tag;
+} FDSource;
+
+static gboolean 
+fd_source_prepare (GSource  *source,
+		   gint     *timeout)
+{
+  FDSource *fd_source = (FDSource *)source;
+  *timeout = -1;
+  
+  return g_cancellable_is_cancelled (fd_source->cancellable);
+}
+
+static gboolean 
+fd_source_check (GSource  *source)
+{
+  FDSource *fd_source = (FDSource *)source;
+
+  return
+    g_cancellable_is_cancelled  (fd_source->cancellable) ||
+    fd_source->pollfd.revents != 0;
+}
+
+static gboolean
+fd_source_dispatch (GSource     *source,
+		    GSourceFunc  callback,
+		    gpointer     user_data)
+
+{
+  GFDSourceFunc func = (GFDSourceFunc)callback;
+  FDSource *fd_source = (FDSource *)source;
+
+  g_assert (func != NULL);
+
+  return (*func) (user_data, fd_source->pollfd.revents, fd_source->pollfd.fd);
+}
+
+static void 
+fd_source_finalize (GSource *source)
+{
+  FDSource *fd_source = (FDSource *)source;
+
+  if (fd_source->cancelled_tag)
+    g_cancellable_disconnect (fd_source->cancellable,
+			      fd_source->cancelled_tag);
+
+  if (fd_source->cancellable)
+    g_object_unref (fd_source->cancellable);
+}
+
+static GSourceFuncs fd_source_funcs = {
+  fd_source_prepare,
+  fd_source_check,
+  fd_source_dispatch,
+  fd_source_finalize
+};
+
+/* Might be called on another thread */
+static void
+fd_source_cancelled_cb (GCancellable *cancellable,
+			gpointer data)
+{
+  /* Wake up the mainloop in case we're waiting on async calls with FDSource */
+  g_main_context_wakeup (NULL);
+}
+
+/* Two __ to avoid conflict with gio version */
+GSource *
+__g_fd_source_new (int fd,
+		   gushort events,
+		   GCancellable *cancellable)
+{
+  GSource *source;
+  FDSource *fd_source;
+
+  source = g_source_new (&fd_source_funcs, sizeof (FDSource));
+  fd_source = (FDSource *)source;
+
+  if (cancellable)
+    fd_source->cancellable = g_object_ref (cancellable);
+  
+  fd_source->pollfd.fd = fd;
+  fd_source->pollfd.events = events;
+  g_source_add_poll (source, &fd_source->pollfd);
+
+  if (cancellable)
+    fd_source->cancelled_tag =
+      g_cancellable_connect (cancellable,
+			     (GCallback)fd_source_cancelled_cb,
+			     NULL, NULL);
+  
+  return source;
+}
+
+/*************************************************************************
+ *                                                                       *
+ *      dbus mainloop integration for async ops                          *
+ *                                                                       *
+ *************************************************************************/
+
+static gint32 main_integration_data_slot = -1;
+static GOnce once_init_main_integration = G_ONCE_INIT;
+
+/**
+ * A GSource subclass for dispatching DBusConnection messages.
+ * We need this on top of the IO handlers, because sometimes
+ * there are messages to dispatch queued up but no IO pending.
+ * 
+ * The source is owned by the connection (and the main context
+ * while that is alive)
+ */
+typedef struct 
+{
+  GSource source;
+  
+  DBusConnection *connection;
+  GSList *ios;
+  GSList *timeouts;
+} DBusSource;
+
+typedef struct
+{
+  DBusSource *dbus_source;
+  GSource *source;
+  DBusWatch *watch;
+} IOHandler;
+
+typedef struct
+{
+  DBusSource *dbus_source;
+  GSource *source;
+  DBusTimeout *timeout;
+} TimeoutHandler;
+
+static gpointer
+main_integration_init (gpointer arg)
+{
+  if (!dbus_connection_allocate_data_slot (&main_integration_data_slot))
+    g_error ("Unable to allocate data slot");
+
+  return NULL;
+}
+
+static gboolean
+dbus_source_prepare (GSource *source,
+		     gint    *timeout)
+{
+  DBusConnection *connection = ((DBusSource *)source)->connection;
+  
+  *timeout = -1;
+
+  return (dbus_connection_get_dispatch_status (connection) == DBUS_DISPATCH_DATA_REMAINS);  
+}
+
+static gboolean
+dbus_source_check (GSource *source)
+{
+  return FALSE;
+}
+
+static gboolean
+dbus_source_dispatch (GSource     *source,
+		      GSourceFunc  callback,
+		      gpointer     user_data)
+{
+  DBusConnection *connection = ((DBusSource *)source)->connection;
+
+  dbus_connection_ref (connection);
+
+  /* Only dispatch once - we don't want to starve other GSource */
+  dbus_connection_dispatch (connection);
+  
+  dbus_connection_unref (connection);
+
+  return TRUE;
+}
+
+static gboolean
+io_handler_dispatch (gpointer data,
+                     GIOCondition condition,
+                     int fd)
+{
+  IOHandler *handler = data;
+  guint dbus_condition = 0;
+  DBusConnection *connection;
+
+  connection = handler->dbus_source->connection;
+  
+  if (connection)
+    dbus_connection_ref (connection);
+  
+  if (condition & G_IO_IN)
+    dbus_condition |= DBUS_WATCH_READABLE;
+  if (condition & G_IO_OUT)
+    dbus_condition |= DBUS_WATCH_WRITABLE;
+  if (condition & G_IO_ERR)
+    dbus_condition |= DBUS_WATCH_ERROR;
+  if (condition & G_IO_HUP)
+    dbus_condition |= DBUS_WATCH_HANGUP;
+
+  /* Note that we don't touch the handler after this, because
+   * dbus may have disabled the watch and thus killed the
+   * handler.
+   */
+  dbus_watch_handle (handler->watch, dbus_condition);
+  handler = NULL;
+
+  if (connection)
+    dbus_connection_unref (connection);
+  
+  return TRUE;
+}
+
+static void
+io_handler_free (IOHandler *handler)
+{
+  DBusSource *dbus_source;
+  
+  dbus_source = handler->dbus_source;
+  dbus_source->ios = g_slist_remove (dbus_source->ios, handler);
+  
+  g_source_destroy (handler->source);
+  g_source_unref (handler->source);
+  g_free (handler);
+}
+
+static void
+dbus_source_add_watch (DBusSource *dbus_source,
+		       DBusWatch *watch)
+{
+  guint flags;
+  GIOCondition condition;
+  IOHandler *handler;
+  int fd;
+
+  if (!dbus_watch_get_enabled (watch))
+    return;
+  
+  g_assert (dbus_watch_get_data (watch) == NULL);
+  
+  flags = dbus_watch_get_flags (watch);
+
+  condition = G_IO_ERR | G_IO_HUP;
+  if (flags & DBUS_WATCH_READABLE)
+    condition |= G_IO_IN;
+  if (flags & DBUS_WATCH_WRITABLE)
+    condition |= G_IO_OUT;
+
+  handler = g_new0 (IOHandler, 1);
+  handler->dbus_source = dbus_source;
+  handler->watch = watch;
+
+#if (DBUS_MAJOR_VERSION == 1 && DBUS_MINOR_VERSION == 1 && DBUS_MICRO_VERSION >= 1) || (DBUS_MAJOR_VERSION == 1 && DBUS_MINOR_VERSION > 1) || (DBUS_MAJOR_VERSION > 1)
+  fd = dbus_watch_get_unix_fd (watch);
+#else
+  fd = dbus_watch_get_fd (watch);
+#endif
+    
+  handler->source = __g_fd_source_new (fd, condition, NULL);
+  g_source_set_callback (handler->source,
+			 (GSourceFunc) io_handler_dispatch, handler,
+                         NULL);
+  g_source_attach (handler->source, NULL);
+ 
+  dbus_source->ios = g_slist_prepend (dbus_source->ios, handler);
+  dbus_watch_set_data (watch, handler,
+		       (DBusFreeFunction)io_handler_free);
+}
+
+static void
+dbus_source_remove_watch (DBusSource *dbus_source,
+			  DBusWatch *watch)
+{
+  dbus_watch_set_data (watch, NULL, NULL);
+}
+
+static void
+timeout_handler_free (TimeoutHandler *handler)
+{
+  DBusSource *dbus_source;
+
+  dbus_source = handler->dbus_source;
+  dbus_source->timeouts = g_slist_remove (dbus_source->timeouts, handler);
+
+  g_source_destroy (handler->source);
+  g_source_unref (handler->source);
+  g_free (handler);
+}
+
+static gboolean
+timeout_handler_dispatch (gpointer      data)
+{
+  TimeoutHandler *handler = data;
+
+  dbus_timeout_handle (handler->timeout);
+  
+  return TRUE;
+}
+
+static void
+dbus_source_add_timeout (DBusSource *dbus_source,
+			 DBusTimeout *timeout)
+{
+  TimeoutHandler *handler;
+  
+  if (!dbus_timeout_get_enabled (timeout))
+    return;
+  
+  g_assert (dbus_timeout_get_data (timeout) == NULL);
+
+  handler = g_new0 (TimeoutHandler, 1);
+  handler->dbus_source = dbus_source;
+  handler->timeout = timeout;
+
+  handler->source = g_timeout_source_new (dbus_timeout_get_interval (timeout));
+  g_source_set_callback (handler->source,
+			 timeout_handler_dispatch, handler,
+                         NULL);
+  g_source_attach (handler->source, NULL);
+
+  /* handler->source is owned by the context here */
+  dbus_source->timeouts = g_slist_prepend (dbus_source->timeouts, handler);
+
+  dbus_timeout_set_data (timeout, handler,
+			 (DBusFreeFunction)timeout_handler_free);
+}
+
+static void
+dbus_source_remove_timeout (DBusSource *source,
+			    DBusTimeout *timeout)
+{
+  dbus_timeout_set_data (timeout, NULL, NULL);
+}
+
+static dbus_bool_t
+add_watch (DBusWatch *watch,
+	   gpointer   data)
+{
+  DBusSource *dbus_source = data;
+
+  dbus_source_add_watch (dbus_source, watch);
+  
+  return TRUE;
+}
+
+static void
+remove_watch (DBusWatch *watch,
+	      gpointer   data)
+{
+  DBusSource *dbus_source = data;
+
+  dbus_source_remove_watch (dbus_source, watch);
+}
+
+static void
+watch_toggled (DBusWatch *watch,
+               void      *data)
+{
+  /* Because we just exit on OOM, enable/disable is
+   * no different from add/remove */
+  if (dbus_watch_get_enabled (watch))
+    add_watch (watch, data);
+  else
+    remove_watch (watch, data);
+}
+
+static dbus_bool_t
+add_timeout (DBusTimeout *timeout,
+	     void        *data)
+{
+  DBusSource *source = data;
+  
+  if (!dbus_timeout_get_enabled (timeout))
+    return TRUE;
+
+  dbus_source_add_timeout (source, timeout);
+
+  return TRUE;
+}
+
+static void
+remove_timeout (DBusTimeout *timeout,
+		void        *data)
+{
+  DBusSource *source = data;
+
+  dbus_source_remove_timeout (source, timeout);
+}
+
+static void
+timeout_toggled (DBusTimeout *timeout,
+                 void        *data)
+{
+  /* Because we just exit on OOM, enable/disable is
+   * no different from add/remove
+   */
+  if (dbus_timeout_get_enabled (timeout))
+    add_timeout (timeout, data);
+  else
+    remove_timeout (timeout, data);
+}
+
+static void
+wakeup_main (void *data)
+{
+  g_main_context_wakeup (NULL);
+}
+
+static const GSourceFuncs dbus_source_funcs = {
+  dbus_source_prepare,
+  dbus_source_check,
+  dbus_source_dispatch
+};
+
+/* Called when the connection dies or when we're unintegrating from mainloop */
+static void
+dbus_source_free (DBusSource *dbus_source)
+{
+  while (dbus_source->ios)
+    {
+      IOHandler *handler = dbus_source->ios->data;
+      
+      dbus_watch_set_data (handler->watch, NULL, NULL);
+    }
+
+  while (dbus_source->timeouts)
+    {
+      TimeoutHandler *handler = dbus_source->timeouts->data;
+      
+      dbus_timeout_set_data (handler->timeout, NULL, NULL);
+    }
+
+  /* Remove from mainloop */
+  g_source_destroy ((GSource *)dbus_source);
+
+  g_source_unref ((GSource *)dbus_source);
+}
+
+void
+_g_dbus_connection_integrate_with_main  (DBusConnection *connection)
+{
+  DBusSource *dbus_source;
+
+  g_once (&once_init_main_integration, main_integration_init, NULL);
+  
+  g_assert (connection != NULL);
+
+  _g_dbus_connection_remove_from_main (connection);
+
+  dbus_source = (DBusSource *)
+    g_source_new ((GSourceFuncs*)&dbus_source_funcs,
+		  sizeof (DBusSource));
+  
+  dbus_source->connection = connection;
+  
+  if (!dbus_connection_set_watch_functions (connection,
+                                            add_watch,
+                                            remove_watch,
+                                            watch_toggled,
+                                            dbus_source, NULL))
+    _g_dbus_oom ();
+
+  if (!dbus_connection_set_timeout_functions (connection,
+                                              add_timeout,
+                                              remove_timeout,
+                                              timeout_toggled,
+                                              dbus_source, NULL))
+    _g_dbus_oom ();
+    
+  dbus_connection_set_wakeup_main_function (connection,
+					    wakeup_main,
+					    dbus_source, NULL);
+
+  /* Owned by both connection and mainloop (until destroy) */
+  g_source_attach ((GSource *)dbus_source, NULL);
+
+  if (!dbus_connection_set_data (connection,
+				 main_integration_data_slot,
+				 dbus_source, (DBusFreeFunction)dbus_source_free))
+    _g_dbus_oom ();
+}
+
+void
+_g_dbus_connection_remove_from_main (DBusConnection *connection)
+{
+  g_once (&once_init_main_integration, main_integration_init, NULL);
+
+  if (!dbus_connection_set_data (connection,
+				 main_integration_data_slot,
+				 NULL, NULL))
+    _g_dbus_oom ();
+}
