--- src/mpdclient.c.orig	2011-02-01 18:13:51 UTC
+++ src/mpdclient.c
@@ -106,7 +106,7 @@ struct _XfmpcMpdclientPrivate
   gboolean                  env_cached;
   gboolean                  connecting;
   guint                     connection_count;
-  GMutex                   *mutex;
+  GMutex                    mutex;
 };
 
 
@@ -275,8 +275,7 @@ xfmpc_mpdclient_init (XfmpcMpdclient *mp
 
   priv->mi = mpd_new_default ();
 
-  if (!g_thread_supported ()) g_thread_init (NULL);
-  priv->mutex = g_mutex_new ();
+  g_mutex_init (&priv->mutex);
 
   mpd_signal_connect_status_changed (priv->mi, (StatusChangedCallback)cb_status_changed, mpdclient);
 }
@@ -288,7 +287,7 @@ xfmpc_mpdclient_finalize (GObject *objec
   XfmpcMpdclientPrivate *priv = XFMPC_MPDCLIENT (mpdclient)->priv;
 
   mpd_free (priv->mi);
-  g_mutex_free (priv->mutex);
+  g_mutex_clear (&priv->mutex);
 
   (*G_OBJECT_CLASS (parent_class)->finalize) (object);
 }
@@ -389,8 +388,6 @@ xfmpc_mpdclient_connect_thread (XfmpcMpd
 
   priv->connecting = FALSE;
 
-  g_mutex_unlock (priv->mutex);
-
   return NULL;
 }
 
@@ -405,7 +402,7 @@ xfmpc_mpdclient_connect (XfmpcMpdclient 
     return TRUE;
 
   /* return FALSE if a we are already trying to connect to mpd */
-  if (!g_mutex_trylock (priv->mutex))
+  if (!g_mutex_trylock (&priv->mutex))
   {
     g_warning ("Already connecting to mpd");
     return FALSE;
@@ -413,8 +410,8 @@ xfmpc_mpdclient_connect (XfmpcMpdclient 
 
   priv->connecting = TRUE;
 
-  thread = g_thread_create ((GThreadFunc) xfmpc_mpdclient_connect_thread,
-          mpdclient, TRUE, NULL);
+  thread = g_thread_new ("0", (GThreadFunc) xfmpc_mpdclient_connect_thread,
+          mpdclient);
 
   while (priv->connecting)
   {
@@ -427,6 +424,8 @@ xfmpc_mpdclient_connect (XfmpcMpdclient 
 
   g_signal_emit (mpdclient, signals[SIG_CONNECTED], 0);
 
+  g_mutex_unlock (&priv->mutex);
+
   return TRUE;
 }
 
